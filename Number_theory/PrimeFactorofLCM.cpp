#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"


const int mx = 1e7+12;

bitset<mx> isPrime;

vector<int> primes;

void PrimesGen(int n){

	for(int i=3; i<=n; i+=2) isPrime[i] = 1;

	int sq = sqrt(n);

	for(int i=3; i<=sq; i+=2){

		if(isPrime[i]){
			for(int j=i*i; j<=n; j+=i){
				isPrime[j] = 0; 
			}
		}
	}

	isPrime[2] = 1;

	primes.push_back(2);

	for(int i=3; i<=n; i+=2){

		if(isPrime[i]){
			primes.push_back(i);
		}
	}
}

vector<ll> prime_factors(ll n){

	vector<ll> factors;

	for(auto &p:primes){

		if( 1ll*p*p > n) break;

		if(n%p == 0){
			
			while(n%p==0){
				factors.push_back(p);
				n /=p;
			}
		}
	}

	if( n > 1){
		factors.push_back(n);
	}

	return factors;
}

ll a[123];

int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 1e7;

  PrimesGen(lim);

  int T; 
  cin>>T;

  for(int tc=1; tc<=T; tc++){

  	int n;
  	cin>>n;

  	for(int i=1; i<=n; i++) cin>>a[i];

  	vector<ll> factors;

  	set<ll> ans ;

  	for(int i=1; i<=n; i++){
  		factors=(prime_factors(a[i]));
  		for(auto p:factors){
  			ans.insert(p);
  		}
  	}

  	cout<<"Case " << "#"<<tc<<": "<<ans.size()<<endl;

  	for(auto &u:ans) cout<<u<<endl;

  }







  return 0;
}