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
ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
#define sqr(a) ((a) * (a))

 
void fraction(dl a){
    cout.unsetf(ios::floatfield);
    cout.precision(a);
    cout.setf(ios::fixed,ios::floatfield);
}


int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  ll a , b;
  cin>>a>>b;

   ll x = gcd( a , b );

  cout<< x << endl;
/*
GCD 
360  = 2^3 * 3^2 * 5^1 
540 = 2^2 * 3^3 * 5^1 
prime factor এর  min পাওয়ার  টা নিব  কারণ :  2^3 / 2^3 ভাগ  দিতে পারবে , কিন্ত 2^2 / 2^3 এটা  ভাগ দিতে পারবেনা  
তাই পাওয়ার এর min valu  টা নিব  যেমন : 

360  = 2^3 * 3^2 * 5^1 / 2^2 * 3^2 * 5^1
540 = 2^2 * 3^3 * 5^1  / 2^2 * 3^2 * 5^1
তাদের min  পাওয়ার  valu 2^2 * 3^2 * 5^1 so GCD(360,540) = 2^2 * 3^2 * 5^1 = 180 ans
LCM 
1800  = 2^3 * 3^2 * 5^2
540 = 2^2 * 3^3 * 5^1
prime factor এর  max পাওয়ার  টা নিব  কারণ :  2^3 / 2^3 ভাগ  দিতে পারবে , কিন্ত 2^2 / 2^3 এটা  ভাগ দিতে পারবেনা  
তাই পাওয়ার এর max valu  টা নিব  যেমন :

1800  = 2^3 * 3^2 * 5^2 // 2^3 * 3^3 * 5*2 max pow গোলা নিয়েছি 
540 =  2^2 * 3^3 * 5^1 

2^3 * 3^3 * 5*2 /  2^3 * 3^2 * 5^2 ভাগ  করা যাচ্ছে  
2^3 * 3^3 * 5*2  / 2^2 * 3^3 * 5^1 ভাগ  করা যাচ্ছে  

তাই আমি পাওয়ার এর max valu টা নিব  
formula is: 
GCD = p1^min , p2^min , p3^min , p4^min... // min টা নিব 
LCM = p1^mx , p2^mx , p3^mx , p4^mx ..... mx  টা নিব 


*/






    return 0;
}


// 1.Understand the problem

// 2.Plan 

// 3.Divide & Conquor  // part by part a problem

// 4. Stuck while coding 

// practice must be