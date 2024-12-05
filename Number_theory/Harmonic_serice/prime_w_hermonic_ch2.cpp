#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int mx = 1e7+12;

bool isPrime[mx];

vector<int> primes;

void PrimeGen(int n){

	for(int i=2; i<=n; i++) isPrime[i] = 1;


	for(int i=2; i<=n; i++){
		for(int j=i+i; j<=n; j+=i){
			isPrime[j] = 0;
		}
	}

	for(int i=2; i<=n; i++){
		if(isPrime[i]==1){
			primes.push_back(i);
		}
	}
}



int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

// time complexit is: O(n*ln(n))

  int lim = 20;


  PrimeGen(lim);


  for(auto u:primes){
  	cout<<u<<endl;
  }







  return 0;
}