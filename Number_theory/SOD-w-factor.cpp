#include <bits/stdc++.h>
using namespace std;

#define ll long 

const int mx = 1e8+12;

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

// comp is: sqrt(n) / ln (sqrt(n)) 

ll sod ( int n){ // 84 = 2^2 * 3^1 * 7^1

	ll sod = 1;

	for(auto P:primes){ //p = 2

		if( 1ll * P*P > n) break; // sqrt er condition

		if( n % P == 0){
			ll sum = 1; // sum = 2^0
			int pow = 1; // pow = 2^0 = 1

			while( n%P == 0){
				pow*=P; // pow = 2^1
				
				sum+=pow; // sum = 2^0 + 2^1 + 2^2

				n /=P; // 2^1 * 3^1 7^1
			}
			sod*=sum; // sod = (2^0 + 2^1 + 2^2) * (3^0 + 3^1 )
		}

		
	}

	if( n>1){ // 7^1 (n+1) = (7^0+7^1)
		sod *= (n+1);
	}

	return sod; // sod = (2^0 + 2^1 + 2^2) * (3^0 + 3^1) * (7^0 * 7^1) = 224
}

// pow er difrente comibination korteci 

int32_t main() {
  #ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int lim = 1e7;

  PrimesGen(lim);


  cout<<sod(84)<<endl;


  //compleixy is : prime_factor er like sqrt(n)/ln(sqrt(n));







  return 0;
}