#include<bits/stdc++.h>
using namespace std;

// Typedefs and shortcuts for convenience in competitive programming
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

// Macros to simplify common operations
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define U upper_bound
#define L lower_bound
#define all(a) (a).begin(), (a).end()
#define mid(l, r) ((r + l) / 2)

// Common constants for calculations
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;  // For integer comparisons
const ll infLL = 9000000000000000000;  // For long long comparisons
#define MOD 1000000007

// Utility macros for specific tasks
#define mem(a, b) memset(a, b, sizeof(a))  // Initialize an array with a specific value
#define gcd(a, b) __gcd(a, b)              // Compute the greatest common divisor
#define sqr(a) ((a) * (a))                 // Square of a number

// Function to set precision for floating-point numbers
void fraction(dl a) {
    cout.unsetf(ios::floatfield);
    cout.precision(a);
    cout.setf(ios::fixed, ios::floatfield);
}

const int mx = 1e8 + 12; // Maximum limit for prime generation
bitset<mx> isPrime;      // Bitset to store prime status (1 for prime, 0 for non-prime)
vector<int> primes;      // Vector to store all prime numbers

// Function to generate all prime numbers up to 'n' using the Sieve of Eratosthenes
void PrimesGen(int n) {
    // Mark all odd numbers as potential primes (even numbers >2 are not prime)
    for (int i = 3; i <= n; i += 2) isPrime[i] = 1;

    // Optimization: Only go up to sqrt(n) for marking multiples
    int sq = sqrt(n);

    // Mark multiples of each prime as non-prime
    for (int i = 3; i <= sq; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0; 
            }
        }
    }

    // Manually add 2 to the primes list (only even prime number)
    primes.push_back(2);

    // Add all remaining odd primes to the list
    for (int i = 3; i <= n; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

const int MX = 5e6 + 124; // Maximum limit for Euler's Totient Function calculations
ll phi[MX];              // Array to store phi values

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // Optimize input and output operations
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int lim = 5e6;  // Limit for phi calculations

    // Step 1: Generate all prime numbers up to 'lim'
    PrimesGen(lim);

    // Step 2: Initialize phi array (phi[i] = i for all i)
    for (int i = 1; i <= lim; i++) phi[i] = i;

    // Step 3: Compute phi values using the formula:
    // phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... for all prime factors p1, p2, ...
    for (auto p : primes) {
        for (int j = p; j <= lim; j += p) {
            phi[j] /= p;         // Divide by the prime
            phi[j] *= (p - 1);   // Multiply by (p - 1)
        }
    }

    // Step 4: Output the phi values for the first 10 numbers
    for (int i = 1; i <= 10; i++) {
        cout << i << ": ";
        cout << phi[i] << endl;
    }

    return 0;
}
