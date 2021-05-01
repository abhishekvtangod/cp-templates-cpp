struct topo_sort{
	vector<vector<int>> adj;
	int n;
	vector<int> visited;
	vector<int> ans;

	void init(int sz){
		n = sz;
		visited.resize(n);
		adj.resize(n);
		for(auto& u: visited){
			u = 0;
		}
	}

	int dfs(int s){
		int cyc = 0;
		visited[s] = 1;
		for(auto u: adj[s]){
			if(!visited[u]){
				cyc = max({cyc, dfs(u)});
			} else if(visited[u] == 1){
				cyc = 1; //cycle exists in DAG
			}
		}
		visited[s] = 2;
		ans.push_back(s);
		return cyc;
	}

	// if dfs returns 1, they cycle exists in DAG, so no topo_sort

	// topo order: reverse of ans
	void topo_order(){
		reverse(ans.begin(), ans.end());
		for(auto u: ans){
			cout << u << " ";
		}
		cout << endl;
	}



};