#include <bits/stdc++.h>
using namespace std;


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);



  //3.using divisor list O(n)

  // O(n) e  some of number of divisor bar kore dibe
  int n = 5;

  int snod = 0;

  for(int i=1; i<=n; i++){

	int contributionI = n/i;

	cout<< i << ": " << contributionI <<endl;

	snod += contributionI;
  }

  cout<<snod<<endl;







  return 0;
}