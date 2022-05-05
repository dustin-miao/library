#pragma region point

#ifndef POINT_HPP
#define POINT_HPP

namespace geo {
	const double EPS = 1e-9;

	template<typename T>
	class point {
		static_assert(is_arithmetic<T>::value, "T must be an arithmetic type");

	public:
		T x, y;

		point() : x(T{}), y(T{}) {}

		point(const T &_x, const T &_y) : x(_x), y(_y) {}

		template<typename S> 
		operator point<S>() const { return point<S>(static_cast<S>(x), static_cast<S>(y)); }

		template<typename S>
		point &operator=(const point<S> &p) { x = p.x; y = p.y; return *this; }

		point &operator+=(const point &p) { x += p.x; y += p.y; return *this; }

		point &operator-=(const point &p) { x -= p.x; y -= p.y; return *this; }

		point &operator*=(const T &s) { x *= s; y *= s; return *this; }

		point &operator/=(const T &s) { x /= s; y /= s; return *this; }

		void swap(point &p) { swap(x, p.x); swap(y, p.y); }
	};

	template<typename T>
	point<T> make_point(const T &x, const T &y) { return point<T>(x, y); }

	template<typename T>
	void swap(point<T> &p, point<T> &q) { p.swap(q); }

	template<typename T>
	point<T> operator-(const point<T> &p) { return point<T>(-p.x, -p.y); }

	template<typename T>
	point<T> operator+(point<T> p, const point<T> &q) { return p += q; }

	template<typename T>
	point<T> operator-(point<T> p, const point<T> &q) { return p -= q; }

	template<typename T>
	point<T> operator*(point<T> p, const T &s) { return p *= s; }

	template<typename T>
	point<T> operator*(const T &s, point<T> p) { return p *= s; }

	template<typename T>
	point<T> operator/(point<T> p, const T &s) { return p /= s;}

	template<typename T>
	T dot(const point<T> &p, const point<T> &q) { return p.x * q.x + p.y * q.y; }

	template<typename T>
	T operator*(const point<T> &p, const point<T> &q) { return dot(p, q); }

	template<typename T>
	T cross(const point<T> &p, const point<T> &q) { return p.x * q.y - p.y * q.x; }

	template<typename T>
	T operator^(const point<T> &p, const point<T> &q) { return cross(p, q); }

	template<typename T>
	bool operator==(const point<T> &p, const point<T> &q) { 
		if constexpr (is_integral<T>::value)
			return p.x == q.x && p.y == q.y; 
		else 
			return abs(p.x - q.x) <= EPS && abs(p.y - q.y) <= EPS;
	} 

	template<typename T>
	bool operator!=(const point<T> &p, const point<T> &q) { return !(p == q); }

	template<typename T>
	bool operator<(const point<T> &p, const point<T> &q) { return p.x < q.x || (p.x == q.x && p.y < q.y); }

	template<typename T>
	bool operator>(const point<T> &p, const point<T> &q) { return q < p; }

	template<typename T>
	bool operator<=(const point<T> &p, const point<T> &q) { return !(p > q); }

	template<typename T>
	bool operator>=(const point<T> &p, const point<T> &q) { return !(p < q); }

	template<typename T>
	double angle(const point<T> &p) { return atan2(p.y, p.x); }

	template<typename T>
	double angle(const point<T> &p, const point<T> &q) { return static_cast<double>(p ^ q) / (p * q); }

	template<typename T, typename S>
	auto rotate(const point<T> &p, const S &cos_a, const S &sin_a) { return make_point(cos_a * p.x - sin_a * p.y, sin_a * p.x + cos_a * p.y); }

	template<typename T, typename S>
	auto rotate(const point<T> &p, const S &a) { return rotate(p, cos(a), sin(a)); }

	template<typename T, typename S>
	auto rotate(const point<T> &p, const S &a, const point<T> &o) { return o + rotate(p - o, a); }

	template<typename T>
	T abs(const point<T> &p) { return p * p; }

	template<typename T>
	double norm(const point<T> &p) { return sqrt(abs(p)); }

	template<typename T>
	T dis2(const point<T> &p, const point<T> &q) { return abs(q - p); }

	template<typename T>
	double dis(const point<T> &p, const point<T> &q) { return norm(q - p); }

	template<typename T>
	auto bisector(const point<T> &p, const point<T> &q) { return p * norm(q) + norm(p) * q; }
}

#endif

#pragma endregion point