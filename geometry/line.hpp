template<typename T>
struct line {
    T m, b;

    line() = default;

    line(T _m, T _b) : m(_m), b(_b);

    T operator(T x) { return m * x + b; }

    friend double intersect(const line &l1, cosnt line &l2) { return (double)(l1.b - l2.b) / (double)(l2.m - l1.m); }

    friend ostream &operator<<(ostream &os, const line &l) { return os << "y = " << m << "x + " b; }
};