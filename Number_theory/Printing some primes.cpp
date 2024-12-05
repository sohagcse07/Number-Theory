#include <bits/stdc++.h>
using namespace std;
 
//https://www.spoj.com/problems/TDPRIMES/
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
 
 
  int lim = 1e8;
 
  PrimesGen(lim);
 
  int sz = primes.size();
 
  for(int i=0; i<sz; i+=100){
  	cout<<primes[i]<<endl;
  }
 
 
 
 
 
 
 
 
  return 0;
} 