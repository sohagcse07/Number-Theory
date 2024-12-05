#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7+12;

bitset<mx> isPrime;

vector<int> primes;

void PrimesGen(int n){

	for(int i=3; i<=n; i+=2) isPrime[i] = 1;

	int sq = sqrt(n);


	for(int i = 3; i<=sq; i+=2){
		if(isPrime[i]){
			for(int j = i*i; j<=n; j+=i){
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

// complexiy is : sqrt(n)/ln(sqrt(n))// preme factor er com
int NOD (int n){

	int nod = 1;

	for(auto p:primes){

		if( 1ll * p * p > n) break;// sqrt(n) condition

		if( n % p == 0){
			int cnt = 0;

			while( n % p == 0 ){// 12 = 2^2 * 3^1 
				cnt++; // pow er difrent combination create korteci
				//like 2^0 * 3^0 = 1 , 2^1 * 3^0 = 2 
				// 1 , 2 holo 12 er divisor so..on kore bar korteci 
				// and count korteci

				n/=p;
			} 

			cnt++; //extra zero er jono 1 ta cnt

			nod*=cnt;
		}
	}

	if(n>1){
		nod *=2; //extra zero ace so 2 use korci
	}

	return nod;
}

// comibinaton er fomula holo p1^a1 ,p2^a2, p3^a3 so..on

// NOD = (a1+1) + (a2+1) + (a3+1) // extra 0 er jono 1 add  kora lagtece 


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 1e7;

  PrimesGen(lim);




 cout<<NOD(12)<<endl; //1,2,3,4,6,12



// snod
 int n = 5;
 int snod = 0;

 for(int i=1; i<=n; i++){
 	snod += NOD(i);
 }

cout<<snod<<endl;

  return 0;
}