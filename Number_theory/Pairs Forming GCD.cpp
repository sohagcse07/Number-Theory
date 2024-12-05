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

const int mx = 1e7+123;

bool isPrime[mx];
vi Primes;

void PrimeGen ( int n ){

	for (int i=3; i<=n; i+=2 ) isPrime[i] = 1;

	int sq = sqrt(n);

	for (int i=3; i<=sq; i+=2 ){

		if ( isPrime[i]){

			for (int j= i*i; j<=n; j+=i ){

				isPrime[j] = 0 ;
			}
		}
	}


	Primes.PB(2);

	for (int i=3; i<=n; i+=2 ){

		if ( isPrime[i]){

			Primes.PB(i );
		}
	}
}


int phi[mx];
ll PreSum[mx];


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  int lim = 1e7;
  PrimeGen(lim);


  for (int i=1; i<=lim; i++ ){
  	phi[i] = i;

  }

  for (auto p:Primes ){

  	for (int j= p; j<=lim; j+=p ){

  		phi[j] /=p;
  		phi[j] *= (p-1);
  	}
  }


  for (int i=1; i<=lim; i++ ){

  	PreSum[i]  = PreSum[i-1] + phi[i];
  }



  int T;
  cin>>T;

  for ( int tc=1; tc<=T; tc++ ){

  	int n , p;
  	cin>>n>>p;

  	ll G = -1;

  	ll  L = 1 , R = n;

  	while ( L<=R ){

  		ll mid = ( L + R ) / 2;

  		ll x = n / mid;


  		if ( PreSum[x] >= p ){

  			L = mid +1;

  			G = max ( G , mid );
  		}else{

  			R = mid -1 ;
  		}
  	}



  	cout << "Case " << tc << ": " << G <<endl;
  }



    return 0;
}


// 1.Understand the problem

// 2.Plan 

// 3.Divide & Conquor  // part by part a problem

// 4. Stuck while coding 

// practice must be