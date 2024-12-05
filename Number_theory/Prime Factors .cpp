#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


//https://vjudge.net/problem/UVA-583

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

vector<int> prime_factors(int n){

	vector<int> factors;

	for(auto p:primes){

		if( 1ll* p*p > n) break;

		if(n%p == 0){
			while(n%p == 0){
				factors.push_back(p);

				n/=p;
			}
		}
	}

	if(n > 1){

		factors.push_back(n);
	}

	return factors;
}

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

  int n;

  while( cin>>n){

  	if(n==0) break;

  	bool isNeg = false;

  	if(n < 0){
  		isNeg = true;

  		n *= -1; // positive korteci
  	}

  	vector<int> factors = prime_factors(n);

  	if(isNeg){

  		n*=-1;

  		factors.insert(factors.begin(),-1);
  	}

  	cout<<n<<" = " <<factors[0];

  	for(int i=1; i<factors.size(); i++){
  		cout<<" x " <<factors[i];
  	}
  	cout<<endl;

  }








  return 0;
}