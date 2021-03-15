// union by size

struct dsu{
	int n;
	vector<int> siz, link;
	vector<vector<int>> adj;

	void init(int nodes){
		n = nodes;
		siz.resize(n);
		adj.resize(n);
		for(int i = 0; i < n; i++){
			link[i] = i;
			siz[i] = 1;
		}
	}

	int find_set(int x){
		if(link[x] == x){
			return x;
		}
		return link[x] = find_set(link[x]);
	}

	void unite_sets(int a, int b){
		a = find_set(a);
		b = find_set(b);
		if(a == b){
			return;
		}
		adj[a].push_back(b);
		adj[b].push_back(a);
		if(siz[a] < siz[b]){
			swap(a, b);
		}
		siz[a] += siz[b];
		link[b] = a;
	}

};