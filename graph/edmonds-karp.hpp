#pragma region graph_flow_edmonds_karp

#ifndef EDMONDS_KARP_HPP
#define EDMONDS_KARP_HPP

namespace graph {
	namespace flow {
		template<typename T>
		T edmonds_karp(const vector<vector<pair<int, T>>> &G, int s, int t) {
			int n = G.size();
			T flow = 0, mx = numeric_limits<T>::max();
			vector<vector<T>> cap(n, vector<T>(n, T{}));
			vector<int> par(n);

			vector<vector<int>> U(n);
			for (int u = 0; u < n; u++) {
				for (auto [v, w] : G[u]) {
					cap[u][v] += w;
					U[u].push_back(v);
					U[v].push_back(u);
				}
			}

			while (true) {
				queue<pair<int, T>> q;
				fill(par.begin(), par.end(), -1);
				T nflow = 0;

				q.emplace(s, mx);
				par[s] = s;
				while (!q.empty()) {
					auto [u, f] = q.front(); q.pop();
					for (auto v : U[u]) {
						if (par[v] == -1 && cap[u][v]) {
							par[v] = u;
							if (v == t) {
								nflow = min(f, cap[u][v]);
								goto bfs_end;
							} else {
								q.emplace(v, min(f, cap[u][v]));
							}
						}
					}
				}
				
				bfs_end:

				if (nflow == 0)
					break;
				flow += nflow;
				for (int u = t; u != s; u = par[u]) {
					cap[par[u]][u] -= nflow;
					cap[u][par[u]] += nflow;
				}
			}
			
			return flow;
		}
	}
}


#endif 

#pragma endregion graph_flow_edmonds_karp