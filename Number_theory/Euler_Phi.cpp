#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


//https://forthright48.com/euler-totient-or-phi-function/
//https://www.spoj.com/problems/ETF/


//phi = gcd(a,n) = 1;
const int mx = 1e7+123;

bitset<mx> isPrime ;

vector<int> primes;

void PrimesGen(int n){

	for(int i=3; i<=n; i+=2) isPrime[i] = 1;

	int sq = sqrt(n);

	for(int i=3; i<=sq; i+=2){
		if(isPrime[i]){
			for(int j= i*i; j<=n; j+=i){
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

// formula is N * p1-1/p1*p2-1/p2*pk-1/pk

// sqrt(n) / ln ( sqrt(n) )

int PHI (int n){

	int phi = n; // sob gola N er sate e * hoy thai age N initialaization korci

	for(auto p:primes){

		if( 1ll* p*p > n) break;

		if(n%p == 0){
			while(n%p == 0){	
				n/=p;
			}

			phi /= p; // bag ta age korteci complexity kom korar jono
			p*= (p-1); //phi *= ((p-1)/p)
		}
	}

	if(n > 1){
		phi /= n;
		phi *= (n-1); // phi *= ((n-1)/n)
	}

	return phi;
}

// coder formula n/p1 * (p1-1)

int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 1e7;

  PrimesGen(lim);


  int t;
  cin>>t;

  while(t--){
  	int n;
  	cin>>n;

  	cout<<PHI(n)<<endl;
  }






  return 0;
}