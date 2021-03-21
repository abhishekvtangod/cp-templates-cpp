/**
 *    author:  abhishekvtangod
**/
// #undef _GLIBCXX_DEBUG
// #undef _ABHI
#include<bits/stdc++.h>
using namespace std; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void debug_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << H << ", ";
  debug_out(T...);
}

#ifdef _GLIBCXX_DEBUG
#define debug(x...) cerr << "[" << #x << "]:[", debug_out(x)
#else
#define debug(...) 42
#endif

struct kosaraju{

	vector<vector<int>> adj, trans_adj;
	vector<int> order, component, visited;
	int n;

	void init(int sz){
		n = sz;
		adj.resize(n);
		trans_adj.resize(n);
		visited.resize(n);
		order.clear();
		component.clear();
	}

	void addEdge(int u, int v){
		adj[u].push_back(v);
		trans_adj[v].push_back(u);
	}

	void dfs1(int sr){
		visited[sr] = 1;
		for(auto u: adj[sr]){
			if(!visited[u]){
				dfs1(u);
			}
		}
		order.push_back(sr);
	}

	void dfs2(int sr){
		visited[sr] = 1;
		component.push_back(sr);
		for(auto u: trans_adj[sr]){
			if(!visited[u]){
				dfs2(u);
			}
		}
	}


	vector<vector<int>> _main(){
		vector<vector<int>> components;

		for(int i = 0; i < n;i++){
			visited[i] = 0;
		}

		//search1
		for(int i = 0; i < n;i++){
			if(!visited[i]){
				dfs1(i);
			}
		}

		for(int i = 0; i < n;i++){
			visited[i] = 0;
		}

		//search2
		for(int i =0; i < n;i++){
			int sr = order[n-1-i];
			if(!visited[sr]){
				dfs2(sr);
				components.push_back(component);
				component.clear();
			}
		}
		return components;
	}

};

kosaraju ks;

void solve(){
	int n;
	cin >> n;
	ks.init(n);
	for(int i = 0; i < n; i++){
		int u, v;
		cin >> u >> v;
		ks.addEdge(u, v);
	}
	vector<vector<int>> comp = ks._main();
	for(auto &i: comp){
		for(auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}


}


int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("/home/abhi/Documents/input.txt", "r", stdin);
		freopen("/home/abhi/Documents/output.txt", "w", stdout);
	#endif 
 

	ll t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	

    return 0;
}