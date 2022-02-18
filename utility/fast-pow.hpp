template<typename T>
T fast_pow(T a, T b) { 
	T ret = 1; 
	for (; b; b >>= 1) { 
		if (b & 1) 
			ret = ret * a; 
		a = a * a; 
	} 
	return ret; 
}

template<typename T>
T fast_pow(T a, T b, T mod) { 
	T ret = 1; 
	for (a %= mod; b; b >>= 1) { 
		if (b & 1) 
			ret = ret * a % mod; 
		a = a * a % mod; 
	} 
	return ret; 
}