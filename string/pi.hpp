#pragma region str_pi

#ifndef STR_PI_HPP
#define STR_PI_HPP

namespace str {
	vector<int> pi(const string &s) {
		int n = (int)s.length();
		vector<int> _pi(n);
		for (int i = 1, j; i < n; i++) {
			for (j = _pi[i - 1]; j > 0 && s[j] != s[i]; j = _pi[j - 1]);
			if (s[i] == s[j])
				j++;
			_pi[i] = j;
		}
		return _pi;
	}
}

#endif

#pragma endregion str_pi