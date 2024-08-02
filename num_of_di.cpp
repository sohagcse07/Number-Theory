#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7+12;

vector<int> divisor[mx];


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 10;

  for(int i=1; i<=lim; i++){
  	for(int j=i; j<=lim; j+=i){
  		divisor[j].push_back(i);
  	}
  }


  for(int i=1; i<=lim; i++){
  	cout<<i<<": " ;
  	for(auto u:divisor[i]){
  		cout<<u<<" ";
  	}
  	cout<<endl;
  }




  return 0;
}