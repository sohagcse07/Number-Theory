#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7+123;

bitset<mx> isPrime;

vector <int> primes;

int cntPrime[mx];

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

  int limX = 3200;
  int limY = 60;

  // for this loop tim comp
  //O(limX+limY) = O(3200+60) = 2*10^5
  for(int x = 1; x<=limX; x++){
  	for(int y = 1; y<=limY; y++){

  		int val =( (x*x) + (y*y*y*y));

  		if(val <= lim && isPrime[val]){
  			cntPrime[val] = 1;
  		}
  	}
  }


  // presum calculat lim = 1e7;

  // lim = O(1e7);
  for(int i=1; i<=lim; i++){ // preSum

  	cntPrime[i] = cntPrime[i-1] + cntPrime[i];
  }

  int t;
  cin>>t;


  // t = 1e4
  while(t--){
  	int n; 
  	cin>>n;

  	cout<<cntPrime[n] <<endl;
  }


  // overoall complexity is worst case = O(n) 
  // n = 1e7




  return 0;
}