#pragma region zip

#ifndef ZIP_HPP
#define ZIP_HPP

namespace zip_internal {
	template<typename Iter>
	using select_access_type_for = conditional_t<
		is_same_v<Iter, vector<bool>::iterator> ||
		is_same_v<Iter, vector<bool>::const_iterator>,
		typename Iter::value_type,
		typename Iter::reference
	>;

	template<typename ...Args, size_t ...Index>
	auto any_match_impl(tuple<Args...> const & lhs, tuple<Args...> const & rhs, index_sequence<Index...>) -> bool {
		auto result = false;
		result = (... | (get<Index>(lhs) == get<Index>(rhs)));
		return result;
	}

	template<typename ...Args>
	auto any_match(tuple<Args...> const &lhs, tuple<Args...> const &rhs) -> bool {
		return any_match_impl(lhs, rhs, index_sequence_for<Args...>{});
	}

	template<typename ... Iters>
	class zip_iterator {
	public:
		using value_type = tuple<select_access_type_for<Iters>...>;

		zip_iterator() = delete;

		zip_iterator(Iters &&...iters) : m_iters {forward<Iters>(iters)...} {}

		auto operator++() -> zip_iterator &{
			apply([](auto && ... args) { ((args += 1), ...); }, m_iters);
			return *this;
		}

		auto operator++(int) -> zip_iterator {
			auto tmp = *this;
			++*this;
			return tmp;
		}

		auto operator!=(zip_iterator const &other) {
			return !(*this == other);
		}

		auto operator==(zip_iterator const &other) {
			auto result = false;
			return any_match(m_iters, other.m_iters);
		}

		auto operator*() -> value_type {
			return apply([](auto && ... args) { return value_type(*args...); }, m_iters);
		}

	private:
		tuple<Iters...> m_iters;
	};

	template<typename T>
	using select_iterator_for = conditional_t<
		is_const_v<remove_reference_t<T>>, 
		typename decay_t<T>::const_iterator, 
		typename decay_t<T>::iterator
	>;

	template<typename ...T>
	class zipper {
	public:
		using zip_type = zip_iterator<select_iterator_for<T>...>;

		template<typename ...Args>
		zipper(Args && ... args) : m_args{forward<Args>(args)...} {}

		auto begin() -> zip_type {
			return apply([](auto &&...args){ return zip_type(std::begin(args)...); }, m_args);
		}

		auto end() -> zip_type {
			return apply([](auto && ... args) { return zip_type(std::end(args)...); }, m_args);
		}

	private:
		tuple<T...> m_args;
	};
}

template<typename ...T>
auto zip(T &&...t) { return zip_internal::zipper<T ...>{forward<T>(t)...}; }

#endif

#pragma endregion zip