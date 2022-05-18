#pragma region str_z

#ifndef STR_Z_HPP
#define STR_Z_HPP

namespace str {
	vector<int> z(const string &s) {
		int n = (int)s.size();
		vector<int> _z(n);
		for (int i = 1, l = 0, r = 0; i < n; i++) {
			if (i <= r)
				_z[i] = min(_z[i - l], r - i + 1);
			while (i + _z[i] < n && s[_z[i]] == s[i + _z[i]])
				_z[i]++;
			if (i + _z[i] - 1 > r)
				l = i, r = i + _z[i] - 1;
		}
		return _z;
	}
}

#endif

#pragma endregion str_z