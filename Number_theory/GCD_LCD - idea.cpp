#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void intcode(){
	#ifndef ONLINE_JUDGE
	  	freopen("input.txt", "r", stdin);
	  	freopen("output.txt", "w", stdout);
  	#endif
}

#define gcd(a,b) __gcd(a,b)
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }




int main(){

	intcode();

	int a , b;
	cin>>a>>b;


	cout << __gcd(__gcd(a,b),4704) << endl; 




return 0;

}