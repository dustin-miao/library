#pragma region prefix_sum

#ifndef PREFIX_SUM_HPP
#define PREFIX_SUM_HPP

template<typename T>
vector<T> prefix_sum(vector<T> a) {
	int n = a.size();
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];
	return a;
}

#endif

#pragma endregion prefix_sum