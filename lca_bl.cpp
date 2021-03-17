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

lca_bl lc;
void solve(){
	int n, m;
	cin >> n >> m;
	lc.init(n);
	for(int i = 0; i < m;i++){
		int u, v;
		cin >> u  >> v;
		lc.adj[u].push_back(v);
		lc.adj[v].push_back(u);
	}
	lc.dfs(0, 0);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int u, v;
		cin >> u >> v;
		cout << lc.lca(u, v) << endl;
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