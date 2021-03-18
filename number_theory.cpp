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

struct number_theory{
	int gcd(int x, int y){
		if(!x){
			return y;
		} else if(!y){
			return x;
		}

		return gcd(y, x%y);
	}

	int isprime(int n){
		if(n <= 1){
			return 0;
		} else if(n <= 3){
			return 1;
		}
		if(n%2 == 0 || n%3 == 0){
			return 0;
		}
		for(int i = 5; i * i <= n; i+=6){
			if(n%i == 0 || n%(i+2) == 0){
				return 0;
			}
		}

		return 1;
	}

	int prime[(int)1e8];
	void sieve_of_eratosthenes(int n){
		for(int i = 0; i <= n; i++){
			prime[i] = 1;
		}
		prime[1] = 0;
		for(int i = 2; i*i <= n; i++){
			if(prime[i]){
				for(int j = i*i; j <= n; j += i){
					prime[j] = 0;
				}
			}
		}
	}

};
number_theory nt;

void solve(){
	int a, b;
	cin >> a >> b;
	cout << nt.gcd(a, b) << endl;
	nt.sieve_of_eratosthenes(50);
	for(int i = 0; i < 40; i++){
		cout << i << " " << nt.prime[i] << endl;
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