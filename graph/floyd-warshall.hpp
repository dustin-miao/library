#include "utility/chmin.hpp"

template<typename G>
void floyd_warshall(G &graph, const long long INF = LLONG_MAX) {
	int n = graph.size();
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (graph[i][k] < INF && graph[k][j] < INF)
					chmin(graph[i][j], graph[i][k] + graph[k][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (graph[i][k] < INF && graph[k][j] < INF && graph[k][k] < 0)
					graph[i][j] = -INF;
}