#pragma region str_manacher

#ifndef STR_MANACHER_HPP
#define STR_MANACHER_HPP

namespace str {
	vector<int> manacher(const string &s) {
		int n = s.size();
		vector<int> d1(n), d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
			for (; 0 <= i - k && i + k < n && s[i - k] == s[i + k]; k++);
			d1[i] = k--;
			if (i + k > r) 
				l = i - k, r = i + k;
		}
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
			for (; 0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]; k++);
			d2[i] = k--;
			if (i + k > r) 
				l = i - k - 1, r = i + k;
		}

		vector<int> d(2 * n - 1);
		for (int i = 0; i < n; i++) {
			d[i * 2] = d1[i] * 2 - 1;
			if (i != n - 1)
				d[i * 2 + 1] = d2[i + 1] * 2;
		}
		return d;
	}
}

#endif

#pragma endregion str_manacher
