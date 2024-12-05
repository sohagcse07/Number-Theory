#include <bits/stdc++.h>
using namespace std;

//hermonic serice and pre calculation 

//https://en.wikipedia.org/wiki/Harmonic_series_(mathematics)
//O(n*ln(n))
const int mx = 1e7+123;

int cnt[mx];

int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 10; // 1e7 

  for(int i=1; i<=lim; i++){ //i = 2 
  	for(int j=i; j<=lim; j+=i){ // j = 2 , 4 , 8, 10
  		cnt[j]++; // cnt[2]+++, cnt[4]++,cnt[8]++..son..on
  	}
  }

  for(int i=1; i<=lim; i++){
  	cout<<i<<": " <<cnt[i]<<endl; // like 6:4 // 6 er num of div 4 ta ace
  }

  // num of div formula is: n/1,n/2,n/3,n/4, n/5 so..on
  //like 10/3 = 3 ta dive ace 

  // time com: O(n*ln(n)) , ln = lon hermonic serice
  // O(10^7*ln(10^7)) == 1.6*10^8 1s e run korbe

/*
1 : 1 2 3 4 5 6 7 8 9 10 
2 : 2 4 6 8 10
3 : 3 6 9
4 : 4 8 
5 : 5 10 // n/oi number ta like 10 / 2 = 5 ta divisor acce 2 er 1 to 10 porjonto
*/

// 10/2 // 10 holo multipul and 2 holo divisor 


  return 0;
}