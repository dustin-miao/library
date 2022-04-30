#pragma region graph_util

using u_graph = vector<vector<int>>;

using u_edgelist = vector<pair<int, int>>;

using u_matgraph = vector<vector<bool>>;

u_graph to_graph(size_t n, const u_edgelist &E) {
	u_graph G(n);
	for (auto [u, v] : E)
		G[u].push_back(v);
	return G;
}

u_graph to_graph(const u_matgraph &M) {
	size_t n = M.size();
	u_graph G(n);
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			if (M[u][v])
				G[u].push_back(v);
	return G;
}

u_edgelist to_edgelist(const u_graph &G) {
	size_t n = G.size();
	u_edgelist E;
	for (int u = 0; u < n; u++) 
		for (int v : G[u])
			E.emplace_back(u, v);
	return E;
}

u_edgelist to_edgelist(const u_matgraph &M) {
	size_t n = M.size();
	u_edgelist E;
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			if (M[u][v])
				E.emplace_back(u, v);
	return E;
}

u_matgraph to_matgraph(const u_graph &G) {
	int n = G.size();
	u_matgraph M(n, vector<bool>(n, false));
	for (int u = 0; u < n; u++)
		for (int v : G[u])
			M[u][v] = true;
	return M;
}

u_matgraph to_matgraph(size_t n, const u_edgelist &E) {
	u_matgraph M(n, vector<bool>(n, false));
	for (auto [u, v] : E)
		M[u][v] = true;
	return M;
}

template<typename T>
using graph = vector<vector<pair<int, T>>>;

template<typename T>
using edgelist = vector<tuple<int, int, T>>;

template<typename T>
using matgraph = vector<vector<T>>;

template<typename T>
graph<T> to_graph(size_t n, const edgelist<T> &E) {
	graph<T> G(n);
	for (auto [u, v, w] : E)
		G[u].emplace_back(v, w);
	return G;
}

template<typename T>
graph<T> to_graph(const matgraph<T> &M, const T dval) {
	size_t n = M.size();
	graph<T> G(n);
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			if (M[u][v] != dval)
				G[u].emplace_back(v, M[u][v]);
	return G;
}

template<typename T>
edgelist<T> to_edgelist(const graph<T> &G) {
	size_t n = G.size();
	edgelist<T> E;
	for (int u = 0; u < n; u++)
		for (auto [v, w] : G[u])
			E.emplace_back(u, v, w);
	return E;
}

template<typename T>
edgelist<T> to_edgelist(const matgraph<T> &M, const T dval) {
	size_t n = M.size();
	edgelist<T> E;
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			if (M[u][v] != dval)
				E.emplace_back(u, v, M[u][v]);
	return E;
}

template<typename T>
matgraph<T> to_matgraph(const graph<T> &G, const T dval) {
	size_t n = G.size();
	matgraph<T> M(n, vector<T>(n, dval));
	for (int u = 0; u < n; u++)	
		for (auto [v, w] : G[u])
			M[u][v] = w;
	return M;
}

template<typename T>
matgraph<T> to_matgraph(size_t n, const edgelist<T> &E, const T dval) {
	matgraph<T> M(n, vector<T>(n, dval));
	for (auto [u, v, w] : E)
		M[u][v] = w;
	return M;
}

#pragma endregion graph_util