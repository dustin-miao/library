#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_A"

#include <bits/stdc++.h>
using namespace std;

#include "convolution/complex-convolution.hpp"

const double EPS = 0.005;

int main() {
	string P, T;
	cin >> T >> P;
	int n = T.size(), m = P.size();
	vector<complex<double>> a(n), b(m);
	for (int i = 0; i < n; i++) {
		char c = T[i];
		double the = 2 * PI * ('0' <= c <= '9' ? c - '0' : c - 'a' + 10) / 36;
		a[i] = complex<double>(cos(the), sin(the));
	}
	for (int i = 0; i < m; i++) {
		char c = P[m - i - 1];
		double the = 2 * PI * ('0' <= c <= '9' ? c - '0' : c - 'a' + 10) / 36;
		b[i] = complex<double>(cos(the), -sin(the));
	}
	auto c = conv::complex_convolution(a, b);
	for (int i = 0; i < n; i++)  {
		if (abs(c[m - 1 + i].real() - m) <= EPS && abs(c[m - 1 + i].imag()) <= EPS) {
			cout << i << '\n';
		}
	}
}