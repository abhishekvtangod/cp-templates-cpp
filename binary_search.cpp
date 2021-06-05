/**
 *    author:  abhishekvtangod
**/
// #undef _GLIBCXX_DEBUG
// #undef _ABHI
#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/gcd(a,b)*b  // no overflow
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

string to_string(const string &s){
	return "{" + s + "}";
}

string to_string(const char &c){
	string s = "";
	s += c;
	return s;
}

template <typename A, typename B>
string to_string(const pair<A, B> &p){
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C> &t){
	return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}

template <typename A>
string to_string(A v){
	string res = "{";
	bool f = 0;
	for(const auto &u: v){
		if(f){
			res += ", ";
		}
		f = 1;
		res += to_string(u);
	}
	res += "}";
	return res;
}

void cus_debug() { cerr << "]" << endl; }

template <typename Head, typename... Tail>
void cus_debug(Head H, Tail... T) {
  cerr << to_string(H) << ", ";
  cus_debug(T...);
}

#ifdef _GLIBCXX_DEBUG
#define debug(x...) cerr << "[" << #x << "]:[", cus_debug(x)
#else
#define debug(...) 42
#endif


// returns index of lower_bound of target
ll lowerBound(vector<ll> v, ll target){
	ll n = v.size();
	ll ans = -1;
	ll l = 0, r= n-1;
	while(l <= r){
		ll mid = l + (r - l)/2;
		if(target <= v[mid]){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return ans;
}

// returns index of upper_bound of target
ll upperBound(vector<ll> v, ll target){
	ll n = v.size();
	ll ans = -1;
	ll l = 0, r= n-1;
	while(l <= r){
		ll mid = l + (r - l)/2;
		if(target < v[mid]){
			r = mid - 1;
		}else{
			ans = mid;
			l = mid + 1;
		}
	}
	return l;
}

ll findMinRotatedSortedArray(vector<ll> v, ll target){

}

// ll searchRotatedArray(vector<ll> v, ll target){
// 	ll n = v.size();
// 	ll ans = -1;
// 	ll l = 0, r = n - 1;
// 	while(l <= r){

// 	}
// }

double bsSqrt(ll n){
	
}


// TTTTFFF

// start of CP 2.0
void solve(){
	ll n, x;
	cin >> n >> x;
	vector<ll> v;
	for(int i = 0; i < n; i++){
		ll temp;
		cin >> temp;
		v.push_back(temp);
	}
	cout << lowerBound(v, x) << endl;
	cout << upperBound(v, x) << endl;
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