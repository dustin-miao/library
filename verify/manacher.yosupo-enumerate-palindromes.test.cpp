#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <bits/stdc++.h>
using namespace std;

#include "string/manacher.hpp"

int main() {
	string S;
	cin >> S;
	auto p = str::manacher(S);
	for (int x : p)
		cout << x << ' ';
	cout << '\n';
}