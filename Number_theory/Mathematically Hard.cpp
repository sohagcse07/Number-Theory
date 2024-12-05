#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Constant for maximum limit up to which we will calculate prime numbers and phi values
const int mx = 1e7 + 123;

// Bitset for prime number sieve
bitset<mx> isPrime;

// Vector to store all primes up to 'n'
vector <int> primes;

// Function to generate all primes up to 'n' using the Sieve of Eratosthenes
void PrimesGen(int n) {
    // Mark all odd numbers as potential primes
    for (int i = 3; i <= n; i += 2) isPrime[i] = 1;

    // Calculate square root of 'n' to optimize the sieve loop
    int sq = sqrt(n);

    // Sieve process: Mark all multiples of each prime as non-prime
    for (int i = 3; i <= sq; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0; // Marking multiples of 'i' as non-prime
            }
        }
    }

    // Manually mark 2 as prime, since the loop above only handles odd numbers
    isPrime[2] = 1;

    // Add all primes to the 'primes' vector
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i); // If 'i' is prime, add it to the list
        }
    }
}

// Constant for maximum value of 'phi' array size
const int MX = 5e6 + 123;

// Array to store the Euler’s Totient values for each number
unsigned long long phi[MX];

// Main function
int32_t main() {
    #ifndef ONLINE_JUDGE
    // For local testing, using input and output files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // Speed up input/output operations
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Limit for 'phi' array (can be adjusted based on input size)
    int lim = 5e6;

    // Step 1: Generate all prime numbers up to 'lim'
    PrimesGen(lim);

    // Step 2: Initialize 'phi' values (phi[i] = i for all 'i')
    for (int i = 1; i <= lim; i++) phi[i] = i;

    // Step 3: Calculate Euler’s Totient function for all numbers up to 'lim'
    for (auto p : primes) {
        // For each prime 'p', update the phi values for its multiples
        for (int i = p; i <= lim; i += p) {
            phi[i] /= p;       // Divide by prime 'p'
            phi[i] *= (p - 1); // Multiply by (p - 1)
        }
    }

    // Step 4: Calculate prefix sums of the square of 'phi' values
    for (int i = 1; i <= lim; i++) {
        // Update each phi[i] as the sum of squares of phi[i] and previous phi[i-1]
        phi[i] = (phi[i] * phi[i]) + phi[i - 1];
    }

    // Input number of test cases
    int t;
    cin >> t;

    // Step 5: Process each test case
    for (int tc = 1; tc <= t; tc++) {
        int a, b;
        cin >> a >> b;

        // Output the result for the current test case:
        // The difference between prefix sums: phi[b] - phi[a-1]
        cout << "Case " << tc << ": " << phi[b] - phi[a - 1] << endl;
    }

    return 0;
}
