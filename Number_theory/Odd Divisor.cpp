//In the name of ALLAH

// Insallah one day success will be your

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
 
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define U upper_bound
#define L lower_bound
#define all(a) (a).begin(),(a).end()
#define mid(l,r) ((r+l)/2)

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
 
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define sqr(a) ((a) * (a))

 
void fraction(dl a){
    cout.unsetf(ios::floatfield);
    cout.precision(a);
    cout.setf(ios::fixed,ios::floatfield);
}
/*
ll mx = 1e7+123;

vector<bool> odd_div ( mx + 1 , true );

void solve (){

	for ( int i=1; i<=mx ; i<<=1 ) {
		odd_div[i] = false;
	}


	for (int i=3; i<=mx; i+=2 ){

		for (int j = i ; j<=mx; j+=i ){

			odd_div[j] = true;
		}
	}
}
*/

const int mx = 1e7+123;

bitset<mx> isPrime;

vector<int> primes;

void primesGen ( int n ){

	isPrime[2] = 1;

	primes.PB( 2 );

	for (int i=3; i<=n; i+=2 ) isPrime[i] = 1;

	int sq = sqrt( n );

	for (int i=3; i<=sq; i+=2 ){

		if ( isPrime[i]){

			for ( int j= i*i ; j<=n; j+=i ){

				isPrime[i] = 0;
			}
		}
	}

	for (int i=3; i<=n; i+=2 ){

		if ( isPrime[i]){

			primes.PB( i );
		}
	}
}

bool odd_dive ( ll n ){

	return ( n & ( n - 1 ) != 0 ); // check pow of 2^0 , 2^3 ect 
	// like  n = 8 = 1000  so ( 8 & ( 7 )) == 1000 & 0111 ret F 

	// eta T / F ret korbe 
}


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

/*
  solve();

  int t;
  cin>>t;

  while ( t-- ){

  	ll n;
  	cin>>n;

  	if ( n <= mx ){

  		cout << (odd_div[n] ? "Yes" : "No" ) << endl;
  	}else{

  		if ( (n & ( n - 1 )) == 0 ){
  			
  			cout << "No\n";
  		}else{

  			cout<< "Yes\n";
  		}
  	}
  }

  */

 int lim = 1e7;
 primesGen(lim);

  int t;
  cin>>t;

  while ( t -- ){

  	ll n;
  	cin>>n;

  	if ( odd_dive ( n )){
  		cout << "Yes\n";
  	}else{

  		cout << "No\n";
  	}
  }






    return 0;
}


// 1.Understand the problem

// 2.Plan 

// 3.Divide & Conquor  // part by part a problem

// 4. Stuck while coding 

// practice must be