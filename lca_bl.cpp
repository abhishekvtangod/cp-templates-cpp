// Lowest Common Ancestor - Binary Lifting
struct lca_bl{
	int n, l;
	vector<vector<int>> adj;
	vector<vector<int>> dp;

	vector<int> time_in, time_out;
	int dfs_timer = 0;


	void init(int sz){
		n = sz;
		l = ceil(log2(n));
		adj.resize(n);
		dp.resize(n);
		time_in.resize(n);
		time_out.resize(n);
		for(int i = 0; i < n; i++){
			dp[i].resize(l+1);
		}
	}

	// dfs(root, root);
	void dfs(int sr, int p){

		time_in[sr] = dfs_timer++;
		dp[sr][0] = p;
		for(int i = 1; i <= l; i++){
			dp[sr][i] = dp[dp[sr][i-1]][i-1];
		}

		for(auto u: adj[sr]){
			if(u != p){
				dfs(u, sr);
			}
		}
		time_out[sr] = dfs_timer++;
	}

	int is_ancestor(int u, int v){
		return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
	}

	int lca(int u, int v){
		if(is_ancestor(u, v)){
			return u;
		}
		if(is_ancestor(v, u)){
			return v;
		}

		for(int i = l; i >= 0; i--){
			if(!is_ancestor(dp[u][i], v)){
				u = dp[u][i];
			}
		}

		return dp[u][0];

	}

};