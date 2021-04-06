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

// associative property

struct segtree{
	int n;
	vector<int> tree, lazy;

	void init(int sz){
		n = sz;
		tree.resize(4*n, 0);
		lazy.resize(4*n, 0);
	}

	// a -> input array, idx -> index of the current vertex
	// 1, 0, n-1 (root node starts from index 1)
	void build(int idx, int tl, int tr, vector<int> a){
		if(tl == tr){
			tree[idx] = a[tl];
			return;
		}
		int tm = tl + (tr - tl) / 2;
		build(idx * 2, tl, tm, a);
		build(idx * 2 + 1, tm + 1, tr, a);
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}

	void apply(int ti, int tl, int tr, int val){
		tree[ti] += val * (tr - tl + 1);
		if(tl != tr){ // if not leaf, make it lazy
			lazy[ti] += val;
		}
	}

	void pushdown(int ti, int tl, int tr){
		if(lazy[ti]){
			int tm = tr + (tr - tl) / 2;
			apply(ti*2, tl, tm, lazy[ti]);
			apply(ti*2+1, tm+1, tr, lazy[ti]);
			lazy[ti] = 0; //not lazy anymore
		}
	}

	void r_update(int ti, int tl, int tr, int l, int r, int val){
		//no overlap  [l..r tl...tr l...r]
		if(l > tr || r < tl){
			return;
		}
		//complete overlap [l...tl...tr...r]
		if(tl >= l && tr <= r){
			apply(ti, tl, tr, val);
			return;
		}

		//partial overlap
		pushdown(ti, tl, tr); // remove lazy tag before moving down
		int tm = tr + (tr - tl) / 2;
		r_update(ti*2, tl, tm, l, r, val);
		r_update(ti*2+1, tm+1, tr, l, r, val);
		tree[ti] = tree[ti*2] + tree[ti*2+1];
	}

	// void pt_update(int idx, int tl, int tr, int pos, int new_val){
	// 	if(tl == pos && tr == pos){
	// 		tree[idx] = new_val;
	// 		return;
	// 	}

	// 	//update point is outside node range
	// 	// pos tl... tr pos
	// 	if(pos < tl || pos > tr){
	// 		return;
	// 	}

	// 	// update point is inside node range
	// 	int tm = tl + (tr - tl)/2;	// [tl, tm] and [tm+1, tr]
	// 	update(idx*2, tl, tm, pos, new_val);
	// 	update(idx*2+1, tm+1, tr, pos, new_val);
	// 	tree[idx] = tree[idx*2] + tree[idx*2+1]; // sum of left and right

	// }

	int query(int ti, int tl, int tr, int left, int right){
		//no overlap
		// left...right tl...tr left...right
		if(left > tr || right < tl){
			return 0;
		}
		// complete overlap
		// left...tl...tr...right
		if(left<=tl && right >= tr){
			return tree[ti];
		}
		// partial overlap
		pushdown(ti, tl, tr); // remove lazy tag before moving down
		
		int tm = tl + (tr - tl)/2;	// [tl, tm] and [tm+1, tr]
		int ans = 0;
		ans += query(ti*2, tl, tm, left, right);
		ans += query(ti*2+1, tm+1, tr, left, right);
		return ans;
	}

};

segtree st;

void solve(){
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int tm; cin >> tm;
		v.push_back(tm);
	}
	st.init(n);
	st.build(1, 0, n-1, v);

	for(int i = 0; i < 4*n; i++){
		cout << st.tree[i] << " ";
	}
	cout << endl;
	cout << st.query(1, 0, n-1, 0, 4) << endl;
	// st.update(1, 0, n-1, 4, 0);
	// st.update(1, 0, n-1, 3, 1); 
	for(int i = 0; i < 4*n; i++){
		cout << st.tree[i] << " ";
	}
	cout << endl;
	
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