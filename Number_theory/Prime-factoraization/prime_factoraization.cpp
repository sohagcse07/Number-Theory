#include <bits/stdc++.h>
using namespace std;

//kono ekta n ke prime diya pokhas kora jay take primeFactor vole

//https://forthright48.com/prime-factorization-of-integer/

// sqrt(n)/ln(sqrt(n)) + log2(n) 
// log2(n) holo bito er loop er jono 
// sqrt(n)/ln(sqrt(n)) hobe primes er loop er jono 
const int mx = 1e7+12;

bitset<mx> isPrime;

vector<int> primes;

void PrimesGen (int n){

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


/// sqrt(n)/ln(sqrt(n)) + log2(n) complexity
vector<int> primeFactor (int n){ // n = 40131

	vector <int> factor;

//2 , 3 ,5 , 7 , 11 , 13
	for(auto p:primes){ 

		if( 1ll * p * p > n) break; 

		if(n%p==0){
			while(n%p==0){ // loge2(n)
				factor.push_back(p); //{3,3,7,7,7}

				n/=p;
			}
		}
	}

	if(n>1){
		factor.push_back(n); //{3,3,7,7,7,13}
	}

	return factor;
}


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 1e7;

  PrimesGen(lim);


  vector<int> fact = primeFactor(40131);

  for(auto P:fact){
  	cout<<P<<",";
  }cout<<endl;



//kono ekt  N ke 2 diya log2(n) bar bag kora jay 





  return 0;
}