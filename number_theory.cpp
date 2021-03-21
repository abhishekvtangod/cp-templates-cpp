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
	// gcd(x, y) = gcd(x, y%x);
	int gcd(int x, int y){
		if(x > y){
			return gcd(y, x);
		}
		if(!x){
			return y;
		}
		return gcd(x, y%x);
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

	vector<int> primesList;
	void genPrimes(int n){
		sieve_of_eratosthenes(n);
		for(int i = 2; i <= n; i++){
			if(prime[i]){
				primesList.push_back(i);
			}
		}
	}

	vector<int> fac;
	void pFactors(int n){
		genPrimes(n);
		for(int i = 0; primesList[i]*primesList[i] <= n; i++){
			while(n%primesList[i] == 0){
				fac.push_back(primesList[i]);
				n/=primesList[i];
			}
		}
		if(n > 1){
			fac.push_back(n);
		}
		// sort(fac.begin(), fac.end());
	}



	vector<int> divs;
	void getDivs(int n){
		for(int i = 1; i*i <= n ; i++){
			if(n%i==0){
				divs.push_back(i);
				if(i != n/i){
					divs.push_back(n/i);
				}
			}
		}
	}

	vector<int> pf;
	void getPrimeFactors(int n){
		for(int i = 2; i*i <= n; i++){
			while(n%i==0){
				pf.push_back(i);
				n/=i;
			}
		}
		if(n!=1){
			pf.push_back(n);
		}
	}




};
number_theory nt;

void solve(){
	

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