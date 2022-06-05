#pragma region str_hash

#ifndef STR_HASH_HPP
#define STR_HASH_HPP

namespace str {
	namespace hash_internal {
		const int MAX_N = 1e6 + 5;
		const int M1 = 1e9 + 7, M2 = 1e9 + 9;
		struct pair_hash {
			int h1, h2;

			pair_hash() : h1(), h2() {}

			pair_hash(int _h1, int _h2) : h1(_h1), h2(_h2) {}

			pair_hash operator+=(const pair_hash &p) {
				h1 += p.h1;
				if (h1 >= M1)
					h1 -= M1;
				h2 += p.h2;
				if (h2 >= M2)
					h2 -= M2;
				return *this;
			}

			pair_hash operator-=(const pair_hash &p) {
				h1 -= p.h1;
				if (h1 < 0)
					h1 += M1;
				h2 -= p.h2;
				if (h2 < 0)
					h2 += M2;
				return *this;
			}

			pair_hash operator*=(const pair_hash &p) {
				h1 = (static_cast<long long>(h1) * p.h1) % M1;
				h2 = (static_cast<long long>(h2) * p.h2) % M2;
				return *this;
			}

			template<typename T>
			pair_hash operator*=(const T &s) { 
				h1 = (static_cast<long long>(h1) * s) % M1;
				h2 = (static_cast<long long>(h2) * s) % M2;
				return *this;
			}

			bool operator==(const pair_hash &p) const { return h1 == p.h1 && h2 == p.h2; }

			template<typename T = int>
			explicit operator pair<T, T>() const {
				return make_pair(static_cast<T>(h1), static_cast<T>(h2));
			}
		};

		pair_hash operator+(pair_hash p, const pair_hash &q) { return p += q; }

		pair_hash operator-(pair_hash p, const pair_hash &q) { return p -= q; }

		pair_hash operator*(pair_hash p, const pair_hash &q) { return p *= q; }

		template<typename T>
		pair_hash operator*(pair_hash p, const T &s) { return p *= s; }
		template<typename T>
		pair_hash operator*(const T &s, pair_hash p) { return p *= s; }

		ostream &operator<<(ostream &os, const pair_hash &p) { 
			return os << '(' << p.h1 << ", " << p.h2 << ')';
		}

		const pair_hash B(131, 137), I(190839696, 262773725);
		array<pair_hash, MAX_N> bpow, ipow;

		void init_hash_pow() {
			static bool init = false;

			if (init)
				return;
			bpow[0] = ipow[0] = pair_hash(1, 1);
			for (int i = 1; i < MAX_N; i++) {
				bpow[i] = bpow[i - 1] * B;
				ipow[i] = ipow[i - 1] * I;
			}
			init = true;
		}
	}

	using namespace hash_internal;

	struct hash {
		int n;
		vector<pair_hash> roll;

		hash() { init_hash_pow(); };

		hash(const string &s) {
			init_hash_pow();

			n = s.size();
			roll.resize(n + 1);
			for (int i = 1; i <= n; i++) 
				roll[i] = roll[i - 1] + bpow[i - 1] * s[i - 1];
		}

		pair_hash query(int l, int r) const {
			return (roll[r + 1] - roll[l]) * ipow[l];
		}

		pair_hash query() const { return roll[n]; }

		pair_hash operator()(int l, int r) const { return query(l, r); }

		pair_hash operator()() const { return query(); }
	};
}

#endif

#pragma endregion str_hash
