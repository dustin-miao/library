#include "math/inverse.hpp"

#pragma region mint

#ifndef MINT_HPP
#define MINT_HPP

template<typename T>
class Modular {
public:
	using Type = typename decay<decltype(T::value)>::type;
	
	constexpr Modular() : value() {}

	template<typename U>
	Modular(const U &x) { value = normalize(x); }

	template<typename U>
	static Type normalize(const U &x) {
		Type v;
		if (-mod() <= x && x < mod()) 
			v = static_cast<Type>(x);
		else 
			v = static_cast<Type>(x % mod());
		if (v < 0) 
			v += mod();
		return v;
	}

	const Type &operator()() const { return value; }

	template<typename U>
	explicit operator U() const { return static_cast<U>(value); }

	constexpr static Type mod() { return T::value; }

	Modular &operator+=(const Modular &a) { 
		if ((value += a.value) >= mod()) 
			value -= mod(); 
		return *this; 
	}

	Modular &operator-=(const Modular &a) { 
		if ((value -= a.value) < 0) 
			value += mod(); 
		return *this; 
	}

	template<typename U> 
	Modular &operator+=(const U &other) { return *this += Modular(other); }

	template<typename U> 
	Modular &operator-=(const U &other) { return *this -= Modular(other); }

	Modular &operator++() { return *this += 1; }

	Modular &operator--() { return *this -= 1; }

	Modular operator++(int) { 
		Modular result(*this); 
		*this += 1; 
		return result; 
	}

	Modular operator--(int) { 
		Modular result(*this);
		*this -= 1; 
		return result; 
	}

	Modular operator-() const { return Modular(-value); }

	template<typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type
	&operator*=(const Modular &a) {
#ifdef _WIN32
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(a.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
#else
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(a.value));
#endif
		return *this;
	}
	
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type
	&operator*=(const Modular &a) {
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * a.value / mod());
		value = normalize(value * a.value - q * mod());
		return *this;
	}

	template <typename U = T>
	typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type 
	&operator*=(const Modular &a) {
		value = normalize(value * a.value);
		return *this;
	}

	Modular &operator/=(const Modular &other) { return *this *= Modular(math::inverse(other.value, mod())); }

	template<typename U>
	friend bool operator==(const Modular<U>& a, const Modular<U>& b);

	template<typename U>
	friend bool operator<(const Modular<U>& a, const Modular<U>& b);

	template<typename U>
	friend istream &operator>>(istream &is, Modular<U> &a);

private:
	Type value;
};

template<typename T> 
bool operator==(const Modular<T> &a, const Modular<T> &b) { return a.value == b.value; }

template<typename T, typename U> 
bool operator==(const Modular<T> &a, U b) { return a == Modular<T>(b); }

template<typename T, typename U> 
bool operator==(U a, const Modular<T> &b) { return Modular<T>(a) == b; }

template<typename T> 
bool operator!=(const Modular<T> &a, const Modular<T> &b) { return !(a == b); }

template<typename T, typename U> 
bool operator!=(const Modular<T> &a, U b) { return !(a == b); }

template<typename T, typename U> 
bool operator!=(U a, const Modular<T> &b) { return !(a == b); }

template<typename T> 
bool operator<(const Modular<T> &a, const Modular<T> &b) { return a.value < b.value; }

template<typename T> 
Modular<T> operator+(const Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) += b; }

template<typename T, typename U> 
Modular<T> operator+(const Modular<T> &a, U b) { return Modular<T>(a) += b; }

template<typename T, typename U> 
Modular<T> operator+(U a, const Modular<T> &b) { return Modular<T>(a) += b; }

template<typename T> 
Modular<T> operator-(const Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) -= b; }

template<typename T, typename U> 
Modular<T> operator-(const Modular<T> &a, U b) { return Modular<T>(a) -= b; }

template<typename T, typename U> 
Modular<T> operator-(U a, const Modular<T> &b) { return Modular<T>(a) -= b; }

template<typename T> Modular<T> 
operator*(const Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) *= b; }

template<typename T, typename U> 
Modular<T> operator*(const Modular<T> &a, U b) { return Modular<T>(a) *= b; }

template<typename T, typename U> 
Modular<T> operator*(U a, const Modular<T> &b) { return Modular<T>(a) *= b; }

template<typename T> Modular<T> 
operator/(const Modular<T> &a, const Modular<T> &b) { return Modular<T>(a) /= b; }

template<typename T, typename U> 
Modular<T> operator/(const Modular<T> &a, U b) { return Modular<T>(a) /= b; }

template<typename T, typename U> 
Modular<T> operator/(U a, const Modular<T> &b) { return Modular<T>(a) /= b; }

template<typename T, typename U>
Modular<T> fast_pow(const Modular<T> &a, const U &b) {
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	U p = b;
	while (p > 0) {
		if (p & 1) 
			res *= x;
		x *= x;
		p /= 2;
	}
	return res;
}

template<typename T>
string to_string(const Modular<T> &a) { return to_string(a()); }

template<typename T>
ostream &operator<<(ostream &os, const Modular<T> &a) { return os << a(); }

template<typename T>
istream &operator>>(istream &is, Modular<T> &a) {
	typename common_type<typename Modular<T>::Type, long long>::type x;
	is >> x;
	a.value = Modular<T>::normalize(x);
	return is;
}

// /*
using ModType = int;

struct VarMod { static ModType value; };

ModType VarMod::value;

ModType &MOD = VarMod::value;

using mint = Modular<VarMod>;
// */

/*
constexpr int MOD = HERE;

using mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;
*/

#endif

#pragma endregion mint