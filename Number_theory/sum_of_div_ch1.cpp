#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7+12;

int sumOFdiv[mx];


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 12;

  for(int i=1; i<=lim; i++){
  	for(int j=i; j<=lim; j+=i){
  		sumOFdiv[j] += i;
  	}
  }


  for(int i=1; i<=lim; i++){
  	cout<<i<<": "<<sumOFdiv[i]<<endl;
  }








  return 0;
}