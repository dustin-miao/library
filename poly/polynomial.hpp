#include "utility/pi.hpp"

#pragma region polynomial

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

namespace poly {
	namespace polynomial_internal {
		const int MAX_N = 1 << 24; 		// maximum size of polynomial, power of 2
		const int MAX_B = 250; 			// maximum size to run brute force

		mt19937 mst(chrono::steady_clock::now().time_since_epoch().count());

		template<typename T, typename U>
		T fast_pow(T a, U b) {
			T ret = T(1);
			for (; b; b /= 2) {
				if (b & 1)
					ret = ret * a;
				a = a * a;
			}
			return ret;
		}

		template<int mod>
		class Modular {
			int value;

		public:
			constexpr Modular(): value(0) {}

			constexpr Modular(const long long &x): value(x % mod) { if (value < 0) value += mod; }

			Modular inv() const { return fast_pow(*this, mod - 2); }

			Modular operator-() const { return value ? mod - value : 0; }

			Modular operator*(const Modular &t) const { return (long long)value * t.value % mod; }

			Modular operator/(const Modular &t) const { return *this * t.inv(); }

			Modular operator+=(const Modular &t) {
				value += t.value;
				if (value >= mod)
					value -= mod;
				return *this;
			}

			Modular operator-=(const Modular &t) {
				value -= t.value;
				if (value < 0)
					value += mod;
				return *this;
			}

			Modular operator+(const Modular &t) const { return Modular(*this) += t; }

			Modular operator-(const Modular &t) const { return Modular(*this) -= t; }

			Modular operator*=(const Modular &t) { return *this = *this * t; }

			Modular operator/=(const Modular &t) { return *this = *this / t; }

			bool operator==(const Modular &t) const { return value == t.value; }

			bool operator!=(const Modular &t) const { return value != t.value; }

			explicit operator int() const { return value; }

			long long rem() const { return 2 * value > mod ? value - mod : value; }

			/*
			optional<Modular> sqrt() const {
				static Modular y;

				y = *this;
				if (value == 0)
					return 0;
				else if (fast_pow(y, (mod - 1) / 2) != Modular(1))
					return nullopt;
				while (true) {
					Modular z = mst();
					if (z * z == *this)
						return z;

					struct lin {
						Modular a, b;

						lin(Modular a, Modular b = 0): a(a), b(b) {}

						lin operator*(const lin& t) {
							return {
								a * t.a + b * t.b * y,
								a * t.b + b * t.a
							};
						}
					} x(z, 1);

					x = fast_pow(x, (mod - 1) / 2);
					if (x.b != Modular(0))
						return x.b.inv();
				}
			}*/

			optional<Modular> sqrt() const {
				assert(0 <= value && value < mod);
				if (value < 2) 
					return value;
				if (fast_pow(Modular(value), (mod - 1) >> 1) != 1) 
					return nullopt;
				Modular b = 1;
				for (; fast_pow(b, (mod - 1) >> 1) == 1; b += 1);
				int m = mod - 1, e = 0;
				for (; m % 2 == 0; m >>= 1, e++);
				Modular x = fast_pow(Modular(value), (m - 1) >> 1);
				Modular y = Modular(value) * x * x;
				Modular z = fast_pow(Modular(b), m);
				x *= value;
				while (y != 1) {
					int j = 0;
					Modular t = y;
					while (t != Modular(1)) {
						j += 1;
						t *= t;
					}
					z = fast_pow(z, 1 << (e - j - 1));
					x *= z;
					z *= z;
					y *= z;
					e = j;
				}
				return int(x);
			}

			template<int _mod>
			friend istream &operator>>(istream &is, Modular<_mod> &t);
		};

		template<int mod>
		istream &operator>>(istream &is, Modular<mod> &t) {
			int x;
			is >> x;
			t.value = x % mod;
			return is;
		}

		template<int mod>
		ostream &operator<<(ostream &os, const Modular<mod> &t) {
			return os << int(t);
		}

		template<typename T>
		T fact(int n) {
			static array<T, MAX_N> F;
			static bool init = false;

			if (!init) {
				F[0] = T(1);
				for (int i = 1; i < MAX_N; i++)
					F[i] = F[i - 1] * T(i);
				init = true;
			}
			return F[n];
		}

		template<typename T>
		T rfact(int n) {
			static array<T, MAX_N> F;
			static bool init = false;

			if (!init) {
				F[MAX_N - 1] = T(1) / fact<T>(MAX_N - 1);
				for (int i = MAX_N - 2; i >= 0; i--)
					F[i] = F[i + 1] * T(i + 1);
				init = true;
			}
			return F[n];
		}

		namespace fast_fourier_transform {
			using type = double;

			complex<double> w[MAX_N];
			int bitr[MAX_N];

			void init_fast_fourier_transform() {
				static bool init = false;

				if (!init) {
					for (int i = 1; i < MAX_N; i *= 2) {
						int ti = i / 2;
						for (int j = 0; j < i; j++) {
							type ang = PI * j / i;
							w[i + j] = complex<type>(cos(ang), sin(ang));
							if (ti)
								bitr[i + j] = 2 * bitr[ti + j % ti] + (j >= ti);
						}
					}
					init = true;
				}
			}

			void fast_fourier_transform(auto &a, int n) {
				init_fast_fourier_transform();
				if (n == 1)
					return;
				int hn = n / 2;
				for (int i = 0; i < n; i++) {
					int ti = 2 * bitr[hn + i % hn] + (i > hn);
					if (i < ti)
						swap(a[i], a[ti]);
				}
				for (int i = 1; i < n; i *= 2) {
					for (int j = 0; j < n; j += 2 * i) {
						for (int k = j; k < j + i; k++) {
							auto t = a[k + i] * w[i + k - j];
							a[k + i] = a[k] - t;
							a[k] += t;
						}
					}
				}
			}

			void slow_polynomial_multiply(vector<auto> &a, const vector<auto> &b) {
				if (a.empty() || b.empty()) {
					a.clear();
				} else {
					int n = a.size();
					int m = b.size();
					a.resize(n + m - 1);
					for (int k = n + m - 2; k >= 0; k--) {
						a[k] *= b[0];
						for (int j = max(k - n + 1, 1); j < min(k + 1, m); j++)
							a[k] += a[k - j] * b[j];
					}
				}
			}

			template<int mod>
			class discrete_fourier_transform {
				static constexpr int split = 1 << 15;
				vector<complex<type>> A;

			public:
				discrete_fourier_transform(vector<Modular<mod>> const &a, int n): A(n) {
					for (int i = 0; i < min(n, (int)a.size()); i++)
						A[i] = complex<type>(a[i].rem() % split, a[i].rem() / split);
					if (n)
						fast_fourier_transform(A, n);
				}

				auto operator*(discrete_fourier_transform const &B) {
					assert(A.size() == B.A.size());
					int n = A.size();
					if (n == 0)
						return vector<Modular<mod>>();

					vector<complex<type>> C(n), D(n);
					for (int i = 0; i < n; i++) {
						C[i] = A[i] * (B[i] + conj(B[(n - i) % n]));
						D[i] = A[i] * (B[i] - conj(B[(n - i) % n]));
					}

					fast_fourier_transform(C, n);
					fast_fourier_transform(D, n);
					reverse(C.begin() + 1, C.end());
					reverse(D.begin() + 1, D.end());

					int t = 2 * n;
					vector<Modular<mod>> res(n);
					for (int i = 0; i < n; i++) {
						Modular<mod> A0(llround(C[i].real() / t));
						Modular<mod> A1(llround(C[i].imag() / t + D[i].imag() / t));
						Modular<mod> A2(llround(D[i].real() / t));
						res[i] = A0 + A1 * split - A2 * split * split;
					}
					return res;
				}

				complex<type>& operator[](int i) { return A[i]; }

				complex<type> operator [](int i) const { return A[i]; }
			};

			int common_size(int as, int bs) {
				if (as == 0 || bs == 0)
					return 0;
				int n = as + bs - 1;
				while (__builtin_popcount(n) != 1)
					n++;
				return n;
			}

			template<int mod>
			void polynomial_multiply(vector<Modular<mod>> &a, vector<Modular<mod>> b) {
				if (min(a.size(), b.size()) < MAX_B) {
					slow_polynomial_multiply(a, b);
					return;
				}

				auto n = common_size(a.size(), b.size());
				auto A = discrete_fourier_transform<mod>(a, n);
				if (a == b)
					a = A * A;
				else
					a = A * discrete_fourier_transform<mod>(b, n);
			}
		}
	}

	using namespace polynomial_internal;

	template<typename T>
	class polynomial {
		vector<T> coef;

		void normalize() {
			while (!coef.empty() && coef.back() == T())
				coef.pop_back();
		}

	public:
		polynomial() {}

		polynomial(T a0) : coef{a0} { normalize(); }

		polynomial(const vector<T> &t) : coef(t) { normalize(); }

		polynomial operator-() const {
			auto t = *this;
			for (auto &c : t.coef)
				c = -c;
			return t;
		}

		polynomial operator+=(const polynomial &t) {
			coef.resize(max(coef.size(), t.coef.size()));
			for (int i = 0; i < t.coef.size(); i++)
				coef[i] += t.coef[i];
			normalize();
			return *this;
		}

		polynomial operator+(const polynomial &t) const { return polynomial(*this) += t; }

		polynomial operator-=(const polynomial &t) {
			coef.resize(max(coef.size(), t.coef.size()));
			for (int i = 0; i < t.coef.size(); i++)
				coef[i] -= t.coef[i];
			normalize();
			return *this;
		}
		polynomial operator-(const polynomial &t) const { return polynomial(*this) -= t; }

		polynomial modulo_k(int k) const { return vector<T>(coef.begin(), coef.begin() + min(k, (int)coef.size())); }

		polynomial multiply_k(int k) const {
			auto res = coef;
			res.insert(res.begin(), k, 0);
			return res;
		}

		polynomial divide_k(int k) const {
			if (is_zero())
				return polynomial();
			return vector<T>(coef.begin() + min(k, (int)coef.size()), coef.end());
		}

		polynomial substr(int l, int r) const {
			return vector<T>(
				coef.begin() + min(l, (int)coef.size()),
				coef.begin() + min(r, (int)coef.size())
			);
		}

		polynomial operator*=(const polynomial &t) {
			fast_fourier_transform::polynomial_multiply(coef, t.coef);
			normalize();
			return *this;
		}

		polynomial operator*(const polynomial &t) const { return polynomial(*this) *= t; }

		polynomial reverse(int n) const {
			auto res = coef;
			res.resize(max(n, (int)res.size()));
			return vector<T>(res.rbegin(), res.rbegin() + n);
		}

		polynomial reverse() const { return reverse(deg() + 1); }

		int size() const { return coef.size(); }

	private:
		pair<polynomial, polynomial> slow_division(const polynomial &b) const {
			vector<T> A(coef);
			vector<T> res;
			while (A.size() >= b.coef.size()) {
				res.push_back(A.back() / b.coef.back());
				if (res.back() != T(0))
					for (int i = 0; i < b.coef.size(); i++)
						A[A.size() - i - 1] -= res.back() * b.coef[b.coef.size() - i - 1];
				A.pop_back();
			}
			std::reverse(res.begin(), res.end());
			return {res, A};
		}

	public:
		pair<polynomial, polynomial> hint_division(polynomial const &b, polynomial const &binv) const {
			assert(!b.is_zero());
			if (deg() < b.deg())
				return {polynomial{0}, *this};
			int d = deg() - b.deg();
			if (min(d, b.deg()) < MAX_B)
				return slow_division(b);
			polynomial D = (reverse().modulo_k(d + 1) * binv.modulo_k(d + 1)).modulo_k(d + 1).reverse(d + 1);
			return {D, *this - D * b};
		}

		pair<polynomial, polynomial> division(const polynomial &b) const {
			assert(!b.is_zero());
			if (deg() < b.deg())
				return {polynomial{0}, *this};
			int d = deg() - b.deg();
			if (min(d, b.deg()) < MAX_B)
				return slow_division(b);
			polynomial D = (reverse().modulo_k(d + 1) * b.reverse().inv(d + 1)).modulo_k(d + 1).reverse(d + 1);
			return {D, *this - D * b};
		}

	private:
		struct transform {
			polynomial a, b, c, d;

			transform(polynomial a, polynomial b = T(1), polynomial c = T(1), polynomial d = T(0)): a(a), b(b), c(c), d(d) {}

			transform operator *(transform const &t) { return { a*t.a + b*t.c, a*t.b + b*t.d, c*t.a + d*t.c, c*t.b + d*t.d}; }

			transform adj() { return transform(d, -b, -c, a); }

			auto apply(polynomial A, polynomial B) { return make_pair(a * A + b * B, c * A + d * B); }
		};

		template<typename Q>
		static void attatch(vector<Q> &a, vector<Q> const &b) {
			for (auto c : b)
				a.push_back(c);
		}

		static pair<vector<polynomial>, transform> half_gcd(polynomial A, polynomial B) {
			assert(A.deg() >= B.deg());
			int m = (A.deg() + 1) / 2;
			if (B.deg() < m)
				return {{}, {T(1), T(0), T(0), T(1)}};
			auto [ar, Tr] = half_gcd(A.divide_k(m), B.divide_k(m));
			tie(A, B) = Tr.adj().apply(A, B);
			if (B.deg() < m)
				return {ar, Tr};
			auto [ai, R] = A.division(B);
			tie(A, B) = make_pair(B, R);
			int k = 2 * m - B.deg();
			auto [as, Ts] = half_gcd(A.divide_k(k), B.divide_k(k));
			attatch(ar, {ai});
			attatch(ar, as);
			return {ar, Tr * transform(ai) * Ts};
		}

		static pair<vector<polynomial>, transform> full_gcd(polynomial A, polynomial B) {
			vector<polynomial> ak;
			vector<transform> trs;
			while (!B.is_zero()) {
				if (2 * B.deg() > A.deg()) {
					auto [a, Tr] = half_gcd(A, B);
					attatch(ak, a);
					trs.push_back(Tr);
					tie(A, B) = trs.back().adj().apply(A, B);
				} else {
					auto [a, R] = A.division(B);
					ak.push_back(a);
					trs.emplace_back(a);
					tie(A, B) = make_pair(B, R);
				}
			}
			trs.emplace_back(T(1), T(0), T(0), T(1));
			while (trs.size() >= 2) {
				trs[trs.size() - 2] = trs[trs.size() - 2] * trs[trs.size() - 1];
				trs.pop_back();
			}
			return {ak, trs.back()};
		}

	public:
		static polynomial gcd(polynomial A, polynomial B) {
			if (A.deg() < B.deg())
				return full_gcd(B, A);
			auto Tr = fraction(A, B);
			return Tr.d * A - Tr.b * B;
		}

	private:
		polynomial slow_linear_recurrence(int d) const {
			auto R1 = modulo_k(d + 1).reverse(d + 1), R2 = init_xk(d + 1);
			auto Q1 = polynomial(T(1)), Q2 = polynomial(T(0));
			while (!R2.is_zero()) {
				auto [a, nR] = R1.division(R2);
				tie(R1, R2) = make_tuple(R2, nR);
				tie(Q1, Q2) = make_tuple(Q2, Q1 + a * Q2);
				if (R2.deg() < Q2.deg())
					return Q2 / Q2.lead();
			}
			assert(false);
		}

		static transform convergent(auto L, auto R) {
			if (R - L == 1)
				return transform(*L);
			int s = 0;
			for (int i = 0; i < R - L; i++)
				s += L[i].coef.size();
			int c = 0;
			for (int i = 0; i < R - L; i++) {
				c += L[i].coef.size();
				if (2 * c > s)
					return convergent(L, L + i) * convergent(L + i, R);
			}
			assert(false);
		}

	public:
		polynomial linear_recurrence(int d) const {
			if (d < MAX_B)
				return slow_linear_recurrence(d);
			auto R2 = modulo_k(d + 1).reverse(d + 1), R1 = init_xk(d + 1);
			if (R2.is_zero())
				return polynomial(1);
			auto [a, Tr] = full_gcd(R1, R2);
			int dr = (d + 1) - a[0].deg(), dp = 0;
			for (int i = 0; i + 1 < a.size(); i++) {
				dr -= a[i + 1].deg();
				dp += a[i].deg();
				if (dr < dp) {
					auto ans = convergent(begin(a), begin(a) + i + 1);
					return ans.a / ans.a.lead();
				}
			}
			auto ans = convergent(begin(a), end(a));
			return ans.a / ans.a.lead();
		}

	private:
		optional<polynomial> slow_modulo_inverse(polynomial const &t) const {
			auto R1 = *this, R2 = t;
			auto Q1 = polynomial(T(1)), Q2 = polynomial(T(0));
			int k = 0;
			while (!R2.is_zero()) {
				k ^= 1;
				auto [a, nR] = R1.division(R2);
				tie(R1, R2) = make_tuple(R2, nR);
				tie(Q1, Q2) = make_tuple(Q2, Q1 + a * Q2);
			}
			if (R1.deg() > 0)
				return nullopt;
			else
				return (k ? -Q1 : Q1) / R1[0];
		}

	public:
		optional<polynomial> modulo_inverse(polynomial const &t) const {
			assert(!t.is_zero());
			if (false && min(deg(), t.deg()) < MAX_B)
				return slow_modulo_inverse(t);
			auto A = t, B = *this % t;
			auto [a, Tr] = full_gcd(A, B);
			auto g = Tr.d * A - Tr.b * B;
			if (g.deg() != 0)
				return nullopt;
			return -Tr.b / g[0];
		};

		polynomial operator/(const polynomial &t) const { return division(t).first; }

		polynomial operator%(const polynomial &t) const { return division(t).second; }

		polynomial operator/=(const polynomial &t) { return *this = division(t).first; }

		polynomial operator%=(const polynomial &t) { return *this = division(t).second; }

		polynomial operator*=(const T &x) {
			for (auto &c : coef)
				c *= x;
			normalize();
			return *this;
		}

		polynomial operator/=(const T &x) {
			for (auto &c : coef)
				c /= x;
			normalize();
			return *this;
		}

		polynomial operator*(const T &x) const { return polynomial(*this) *= x; }

		polynomial operator/(const T &x) const { return polynomial(*this) /= x; }

		polynomial conjugate() const {
			auto res = *this;
			for (int i = 1; i <= deg(); i += 2)
				res[i] = -res[i];
			return res;
		}

		T eval(T x) const {
			T res(0);
			for (int i = deg(); i >= 0; i--) {
				res *= x;
				res += coef[i];
			}
			return res;
		}

		T operator()(T x) { return eval(x); }

		T lead() const {
			assert(!is_zero());
			return coef.back();
		}

		int deg() const { return (int)coef.size() - 1; }

		bool is_zero() const { return coef.empty(); }

		T operator[](int i) const { return i < 0 || i > deg() ? T(0) : coef[i]; }

		T &operator[](int i) { return coef[i]; }

		bool operator==(const polynomial &t) const { return coef == t.coef; }

		bool operator!=(const polynomial &t) const { return coef != t.coef; }

		polynomial derivative(int k = 1) {
			if (deg() + 1 < k)
				return polynomial(T(0));
			vector<T> res(deg() + 1 - k);
			for (int i = k; i <= deg(); i++)
				res[i - k] = fact<T>(i) * rfact<T>(i - k) * coef[i];
			return res;
		}

		polynomial integral() {
			vector<T> res(deg() + 2);
			for (int i = 0; i <= deg(); i++)
				res[i + 1] = coef[i] / T(i + 1);
			return res;
		}

		int trailing_k() const {
			if (is_zero())
				return -1;
			int res = 0;
			while (coef[res] == T(0))
				res++;
			return res;
		}

		polynomial log(int n) {
			assert(coef[0] == T(1));
			return (derivative().modulo_k(n) * inv(n)).integral().modulo_k(n);
		}

		polynomial exp(int n) {
			if (is_zero())
				return T(1);
			assert(coef[0] == T(0));
			polynomial ans = T(1);
			int a = 1;
			while (a < n) {
				polynomial C = ans.log(2 * a).divide_k(a) - substr(a, 2 * a);
				ans -= (ans * C).modulo_k(a).multiply_k(a);
				a *= 2;
			}
			return ans.modulo_k(n);
		}

	private:
		polynomial pow_bin(long long k, int n) {
			if (k == 0) {
				return polynomial(1).modulo_k(n);
			} else {
				auto t = pow(k / 2, n);
				t *= t;
				return (k % 2 ? *this * t : t).modulo_k(n);
			}
		}

		polynomial hint_pow(long long k, polynomial const &mod, polynomial const &mod_inv) {
			if (k == 0) {
				return polynomial(1);
			} else {
				auto t = hint_pow(k / 2, mod, mod_inv);
				t = (t * t).hint_division(mod, mod_inv).second;
				if (k % 2) {
					t = (t * *this).hint_division(mod, mod_inv).second;
				}
				return t;
			}
		}

	public:

		polynomial pow(long long k, polynomial const &mod) {
			auto mod_inv = mod.reverse().inv(mod.deg() + 1);
			return hint_pow(k, mod, mod_inv);
		}

	private:
		polynomial pow_dn(long long k, int n) {
			if (n == 0) {
				return polynomial(T(0));
			}
			assert((*this)[0] != T(0));
			vector<T> Q(n);
			Q[0] = fast_pow(coef[0], k);
			for (int i = 1; i < (int)n; i++) {
				for (int j = 1; j <= min(deg(), i); j++) {
					Q[i] += coef[j] * Q[i - j] * (T(k) * T(j) - T(i - j));
				}
				Q[i] /= T(i) * coef[0];
			}
			return Q;
		}

	public:
		polynomial pow(long long k, int n) {
			if (is_zero())
				return k ? *this : polynomial(1);
			int i = trailing_k();
			if (i > 0)
				return i * k >= (long long)n ? polynomial(T(0)) : divide_k(i).pow(k, n - i * k).multiply_k(i * k);
			if (min(deg(), (int)n) <= MAX_B)
				return pow_dn(k, n);
			if (k <= MAX_B)
				return pow_bin(k, n);
			T j = coef[i];
			polynomial t = *this / j;
			return fast_pow(j, k) * (t.log(n) * T(k)).exp(n).modulo_k(n);
		}

	public:
		optional<polynomial> sqrt(int n) const {
			if (is_zero())
				return *this;
			int i = trailing_k();
			if (i % 2) {
				return nullopt;
			} else if (i > 0) {
				auto ans = divide_k(i).sqrt(n - i / 2);
				return ans ? ans->multiply_k(i / 2) : ans;
			}
			auto st = (*this)[0].sqrt();
			if (st) {
				polynomial ans = *st;
				int a = 1;
				while (a < n) {
					a *= 2;
					ans -= (ans - modulo_k(a) * ans.inv(a)).modulo_k(a) / 2;
				}
				return ans.modulo_k(n);
			}
			return nullopt;
		}

	private:
		polynomial mulx(T a) const {
			T cur = 1;
			polynomial res(*this);
			for (int i = 0; i <= deg(); i++) {
				res.coef[i] *= cur;
				cur *= a;
			}
			return res;
		}

		polynomial mulx_sq(T a) const {
			T cur = a;
			T total = 1;
			T aa = a * a;
			polynomial res(*this);
			for (int i = 0; i <= deg(); i++) {
				res.coef[i] *= total;
				total *= cur;
				cur *= aa;
			}
			return res;
		}

		vector<T> chirpz_even(T z, int n) const {
			int m = deg();
			if (is_zero())
				return vector<T>(n, 0);
			vector<T> vv(m + n);
			T zi = T(1) / z;
			T zz = zi * zi;
			T cur = zi;
			T total = 1;
			for (int i = 0; i <= max(n - 1, m); i++) {
				if (i <= m) {vv[m - i] = total; }
				if (i < n) {vv[m + i] = total; }
				total *= cur;
				cur *= zz;
			}
			polynomial w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
			vector<T> res(n);
			for (int i = 0; i < n; i++) {
				res[i] = w[i];
			}
			return res;
		}

	public:
		vector<T> chirpz(T z, int n) const {
			auto even = chirpz_even(z, (n + 1) / 2);
			auto odd = mulx(z).chirpz_even(z, n / 2);
			vector<T> ans(n);
			for (int i = 0; i < n / 2; i++) {
				ans[2 * i] = even[i];
				ans[2 * i + 1] = odd[i];
			}
			if (n % 2 == 1) {
				ans[n - 1] = even.back();
			}
			return ans;
		}

	private:
		vector<T> eval(vector<polynomial> &tree, int v, auto l, auto r) {
			if (r - l == 1) {
				return {eval(*l)};
			} else {
				auto m = l + (r - l) / 2;
				auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, m);
				auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, m, r);
				A.insert(end(A), begin(B), end(B));
				return A;
			}
		}

	public:
		vector<T> eval(vector<T> x) {
			int n = x.size();
			if (is_zero()) 
				return vector<T>(n, T(0));
			vector<polynomial> tree(4 * n);
			build(tree, 1, begin(x), end(x));
			return eval(tree, 1, begin(x), end(x));
		}

	private:
		polynomial interpolate(vector<polynomial> &tree, int v, auto l, auto r, auto ly, auto ry) {
			if (r - l == 1) {
				return {*ly / coef[0]};
			} else {
				auto m = l + (r - l) / 2;
				auto my = ly + (ry - ly) / 2;
				auto A = (*this % tree[2 * v]).interpolate(tree, 2 * v, l, m, ly, my);
				auto B = (*this % tree[2 * v + 1]).interpolate(tree, 2 * v + 1, m, r, my, ry);
				return A * tree[2 * v + 1] + B * tree[2 * v];
			}
		}

		static auto resultant(polynomial a, polynomial b) {
			if (b.is_zero()) {
				return 0;
			} else if (b.deg() == 0) {
				return bpow(b.lead(), a.deg());
			} else {
				int pw = a.deg();
				a %= b;
				pw -= a.deg();
				auto mul = bpow(b.lead(), pw) * T((b.deg() & a.deg() & 1) ? -1 : 1);
				auto ans = resultant(b, a);
				return ans * mul;
			}
		}

		static polynomial build(vector<polynomial> &res, int v, auto L, auto R) {
			if (R - L == 1) {
				return res[v] = vector<T>{-*L, 1};
			} else {
				auto M = L + (R - L) / 2;
				return res[v] = build(res, 2 * v, L, M) * build(res, 2 * v + 1, M, R);
			}
		}

	public:
		static auto interpolate(vector<T> x, vector<T> y) {
			int n = x.size();
			vector<polynomial> tree(4 * n);
			return build(tree, 1, begin(x), end(x)).derivative().interpolate(tree, 1, begin(x), end(x), begin(y), end(y));
		}


		static polynomial init_xk(int n) { return polynomial(T(1)).multiply_k(n); }

		static polynomial init_unit(int n) { return polynomial(vector<T>(n, 1)); }

		static polynomial init_exp(int n) { return init_unit(n).borel(); }

		static polynomial cross_correlation(polynomial a, polynomial b) { return a * b.reverse(); }

		polynomial invborel() const {
			auto res = *this;
			for (int i = 0; i <= deg(); i++)
				res.coef[i] *= fact<T>(i);
			return res;
		}

		polynomial borel() const {
			auto res = *this;
			for (int i = 0; i <= deg(); i++)
				res.coef[i] *= rfact<T>(i);
			return res;
		}

		polynomial shift(T a) const { return (init_exp(deg() + 1).mulx(a).reverse() * invborel()).divide_k(deg()).borel(); }

	private:
		polynomial eval_x2() {
			vector<T> res(2 * coef.size());
			for (int i = 0; i < coef.size(); i++)
				res[2 * i] = coef[i];
			return res;
		}

		pair<polynomial, polynomial> bisect() const {
			vector<T> res[2];
			res[0].reserve(deg() / 2 + 1);
			res[1].reserve(deg() / 2 + 1);
			for (int i = 0; i <= deg(); i++) {
				res[i % 2].push_back(coef[i]);
			}
			return {res[0], res[1]};
		}

	public:
		static T kth_recurrence(polynomial P, polynomial Q, long long k) {
			while (k > Q.deg()) {
				int n = Q.coef.size();
				auto [Q0, Q1] = Q.mulx(-1).bisect();
				auto [P0, P1] = P.bisect();

				int N = fast_fourier_transform::common_size((n + 1) / 2, (n + 1) / 2);

				auto Q0f = fast_fourier_transform::discrete_fourier_transform(Q0.coef, N);
				auto Q1f = fast_fourier_transform::discrete_fourier_transform(Q1.coef, N);
				auto P0f = fast_fourier_transform::discrete_fourier_transform(P0.coef, N);
				auto P1f = fast_fourier_transform::discrete_fourier_transform(P1.coef, N);

				if (k % 2)
					P = polynomial(Q0f * P1f) + polynomial(Q1f * P0f);
				else
					P = polynomial(Q0f * P0f) + polynomial(Q1f * P1f).multiply_k(1);
				Q = polynomial(Q0f * Q0f) - polynomial(Q1f * Q1f).multiply_k(1);
				k /= 2;
			}
			return (P * Q.inv(Q.deg() + 1))[k];
		}

		polynomial inv(int n) const {
			auto Q = modulo_k(n);
			if (n == 1)
				return Q.is_zero() ? 0 : Q[0].inv();
			auto [P0, P1] = Q.mulx(-1).bisect();
			int N = fast_fourier_transform::common_size((n + 1) / 2, (n + 1) / 2);

			auto P0f = fast_fourier_transform::discrete_fourier_transform(P0.coef, N);
			auto P1f = fast_fourier_transform::discrete_fourier_transform(P1.coef, N);

			auto TTf = fast_fourier_transform::discrete_fourier_transform((
				polynomial(P0f * P0f) - polynomial(P1f * P1f).multiply_k(1)
			).inv((n + 1) / 2).coef, N);

			return (
				polynomial(P0f * TTf).eval_x2() + polynomial(P1f * TTf).eval_x2().multiply_k(1)
			).modulo_k(n);
		}

		static polynomial compose(polynomial A, polynomial B, int n) {
			int q = std::sqrt(n);
			vector<polynomial> Bk(q);
			auto Bq = B.pow(q, n);
			Bk[0] = polynomial(T(1));
			for (int i = 1; i < q; i++)
				Bk[i] = (Bk[i - 1] * B).modulo_k(n);
			polynomial Bqk(1);
			polynomial ans;
			for (int i = 0; i <= n / q; i++) {
				polynomial cur;
				for (int j = 0; j < q; j++)
					cur += Bk[j] * A[i * q + j];
				ans += (Bqk * cur).modulo_k(n);
				Bqk = (Bqk * Bq).modulo_k(n);
			}
			return ans;
		}

		static polynomial compose_large(polynomial A, polynomial B, int n) {
			if (B[0] != T(0))
				return compose_large(A.shift(B[0]), B - B[0], n);
			int q = std::sqrt(n);
			auto [B0, B1] = make_pair(B.modulo_k(q), B.divide_k(q));
			B0 = B0.divide_k(1);
			vector<polynomial> pw(A.deg() + 1);
			auto getpow = [&](int k) { return pw[k].is_zero() ? pw[k] = B0.pow(k, n - k) : pw[k]; };

			function<polynomial(polynomial const&, int, int)> compose_dac = [&getpow, &compose_dac](polynomial const &f, int m, int N) {
				if (f.deg() <= 0)
					return f;
				int k = m / 2;
				auto [f0, f1] = make_pair(f.modulo_k(k), f.divide_k(k));
				auto [A, B] = make_pair(compose_dac(f0, k, N), compose_dac(f1, m - k, N - k));
				return (A + (B.modulo_k(N - k) * getpow(k).modulo_k(N - k)).multiply_k(k)).modulo_k(N);
			};

			int r = n / q;
			auto Ar = A.derivative(r);
			auto AB0 = compose_dac(Ar, Ar.deg() + 1, n);
			auto Bd = B0.multiply_k(1).derivative();

			polynomial ans = T(0);

			vector<polynomial> B1p(r + 1);
			B1p[0] = polynomial(T(1));
			for (int i = 1; i <= r; i++)
				B1p[i] = (B1p[i - 1] * B1.modulo_k(n - i * q)).modulo_k(n - i * q);
			while (r >= 0) {
				ans += (AB0.modulo_k(n - r * q) * rfact<T>(r) * B1p[r]).multiply_k(r * q).modulo_k(n);
				r--;
				if (r >= 0)
					AB0 = ((AB0 * Bd).integral() + A[r] * fact<T>(r)).modulo_k(n);
			}
			return ans;
		}
	};

	static auto operator*(const auto &a, const polynomial<auto> &b) { return b * a; }

	ostream &operator<<(ostream &os, const polynomial<auto> &p) {
		os << '[';
		if (p.size()) {
			os << p[0];
			for (int i = 1; i < p.size(); i++)
				os << ", " << p[i];
		}
		return os << ']';
	}
}

#endif

#pragma endregion polynomial