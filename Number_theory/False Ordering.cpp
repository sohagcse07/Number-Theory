#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4;

int NOD[mx];


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int lim = 1e3;

// O(n*ln(n))
  for(int i=1; i<=lim; i++){ // harmonic series
  	for (int j = i; j<=lim; j+=i){
  		NOD[j]++;
  	}
  }


  vector<pair<int,int>> v;

  for(int i=1; i<=lim; i++){
  	v.push_back(make_pair(NOD[i] , -i));
  }


  sort(v.begin(),v.end()); // cmd 


  int tc;

  cin>>tc;

  for(int i=1; i<=tc; i++){

  	int n;
  	cin>>n;

  	cout<<"Case " << i << ": " << (v[n-1].second *-1) <<endl;
  }



  return 0;
}