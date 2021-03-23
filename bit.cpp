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


// 1 based indexing
struct bit{
	int n;
	vector<int> tree;

	void init(int _n){
		n = _n;
		tree.resize(_n+1);
	}

	void add(int idx, int val){
		for(; idx <= n; idx += (idx & -idx)){
			tree[idx] += val;
		}
	}

	// void range_add(int l, int r, int val){
	// 	add(l, val);
	// 	add(r+1, -val);
	// }

	// [ (idx - 2^r + 1) to idx ]  (where r is the position of least significant set bit of idx)
	int point_query(int idx){
		ll sum = 0;
		for(; idx > 0; idx -= (idx & -idx)){
			sum += tree[idx];
		}
		return sum;
	}
	int range_query(int l, int r){
		return point_query(r) - point_query(l-1);
	}


};

bit bt;


void solve(){
	int n;
	cin >> n;
	bt.init(n);
	for(int i =1; i <= n ; i++){
		int temp; cin>> temp;
		bt.add(i, temp);
	}
	cout << bt.point_query(4) << endl;
	for(int i : bt.tree){
		cerr << i << " ";
	}
	cerr << endl;
	bt.range_add(2, 4, 100);
	for(int i : bt.tree){
		cerr << i << " ";
	}
	cerr << endl;
	for(int i = 1; i <=n ;i++){
		cout << bt.point_query(i) << endl;
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