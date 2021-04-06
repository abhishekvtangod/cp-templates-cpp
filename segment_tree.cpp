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
struct node{
	int val;
	node(){
		val = 0;
	}
	node(int _val){
		val = _val;
	}

	node oper(node& other_node){
		return node(val + other_node.val);
	}

	node lazy_oper(node& other_node, int size){
		return node(val + other_node.val * size);
	}

};


template<typename node_t>
struct segtree{
	int n;
	vector<node_t> tree, lazy;


	segtree(int _n){
		n = _n;
		tree.resize(4 * n);
		lazy.resize(4 * n);
	}

	// v -> input array, ti -> index of the current vertex in segment tree
	// 1, 0, n-1 (root node starts from index 1)
	void build(vector<int> v){
		build(1, 0, n-1, v);
	}

	void build(int ti, int tl, int tr, vector<int> v){
		if(tl == tr){
			tree[ti] = v[tl];
			return;
		}
		int tm = tl + (tr - tl) / 2;
		build(ti * 2, tl, tm, v);
		build(ti * 2 + 1, tm + 1, tr, v);
		// tree[ti] = tree[ti * 2] + tree[ti * 2 + 1];
		tree[ti] = tree[ti*2].oper(tree[ti*2+1]);
	}

	void apply(int ti, int tl, int tr, node_t upd){
		// tree[ti] += val * (tr - tl + 1);
		tree[ti] = tree[ti].lazy_oper(upd, (tr - tl + 1));
		if(tl != tr){ // if not leaf, make it lazy
			lazy[ti] = lazy[ti].lazy_oper(upd, 1);
		}
		lazy[ti] = node_t();
	}

	void pushdown(int ti, int tl, int tr){
		if(!lazy[ti].val)return;

		int tm = tr + (tr - tl) >> 1;
		apply(ti<<1, tl, tm, lazy[ti]);
		apply(ti<<1|1, tm+1, tr, lazy[ti]);
		lazy[ti] = 0; //not lazy anymore

	}

	// range update
	void r_update(int l, int r, int val){
		node_t upd(val);
		r_update(1, 0, n-1, l, r, upd);
	}
	void r_update(int ti, int tl, int tr, int l, int r, node_t upd){
		//no overlap  [l..r tl...tr l...r]
		if(l > tr || r < tl){
			return;
		}
		//complete overlap [l...tl...tr...r]
		if(tl >= l && tr <= r){
			apply(ti, tl, tr, upd);
			return;
		}

		//partial overlap
		pushdown(ti, tl, tr); // remove lazy tag before moving down
		int tm = tl + (tr - tl) / 2;
		r_update(ti*2, tl, tm, l, r, upd);
		r_update(ti*2+1, tm+1, tr, l, r, upd);
		// tree[ti] = tree[ti*2] + tree[ti*2+1];
		tree[ti] = tree[ti*2].oper(tree[ti*2+1]);
	}

	int query(int l, int r){
		node_t ans = query(1, 0, n-1, l, r);
		return ans.val;
	}

	node_t query(int ti, int tl, int tr, int l, int r){
		//no overlap
		// l...r tl...tr l...r
		if(l > tr || r < tl){
			return 0;
		}
		// complete overlap
		// l...tl...tr...r
		if(l <= tl && r >= tr){
			return tree[ti];
		}
		// partial overlap
		pushdown(ti, tl, tr); // remove lazy tag before moving down
		
		int tm = (tl + (tr - tl) / 2);	// [tl, tm] and [tm+1, tr]
		node_t a = query(ti*2, tl, tm, l, r);
		node_t b = query(ti*2+1, tm+1, tr, l, r);
		return a.oper(b);
	}

};


void solve(){
	int n;
	cin >> n;
	segtree<node> st(n);
	vector<int> v;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	st.build(v);
	st.r_update(1, 3, 100);


	for(int i = 0; i < n; i++){
		int temp = st.query(i, i);
		cout << temp << " " ;
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