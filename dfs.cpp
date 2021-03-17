struct s_dfs{
	vector<vector<int>> adj;
	int n;
	vector<int> visited;

	void init(int sz){
		n = sz;
		visited.resize(n);
		adj.resize(n);
		for(auto& u: visited){
			u = 0;
		}
	}

	void dfs(int src){
		visited[src] = 1;
		for(auto u: adj[src]){
			if(!visited[u]){
				dfs(u);
			}
		}
	}

};

struct generic_dfs{
	vector<vector<int>> adj;
	int n;
	vector<int> visited;

	vector<int> time_in, time_out;
	int dfs_timer = 0;

	void init(int sz){
		n = sz;
		visited.resize(n);
		adj.resize(n);
		time_in.resize(n);
		time_out.resize(n);
		for(auto& u: visited){
			u = 0;
		}
	}

	void dfs(int src){
		time_in[src] = dfs_timer++;
		visited[src] = 1;
		for(auto u: adj[src]){
			if(!visited[u]){
				dfs(u);
			}
		}
		visited[src] = 2;
		time_out[src] = dfs_timer++;
	}

};