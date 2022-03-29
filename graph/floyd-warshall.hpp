#include "utility/chmin.hpp"

template<typename T>
void floyd_warshall(vector<vector<T>> &G, const T dval) {
	int n = G.size();
	for (int i = 0; i < n; i++)
		G[i][i] = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (G[i][k] != dval && G[k][j] != dval) {
					if (G[i][j] == dval)
						G[i][j] = G[i][k] + G[k][j];
					else 
						chmin(G[i][j], G[i][k] + G[k][j]);
				}
			}
		}
	}
}