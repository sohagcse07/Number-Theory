#include <bits/stdc++.h>
using namespace std;
// kono ekta num er divisor er goler sum ke snod vole
//https://forthright48.com/divisor-summatory-function/
//SNOD(5)=NOD(1)+NOD(2)+NOD(3)+NOD(4)+NOD(5)=1+2+2+3+2=10.

int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  //1.brute force O(n^2)
  /*
  int n = 5;
  int snod = 0;

  for(int i=1; i<=n; i++){
  	int nodi = 0;

  	for(int j = 1; j<=i; j++){
  		if( i%j ==0){
  			nodi++;  		}
  	}

  	snod += nodi;
  }


  cout<<snod<<endl;

*/
//2.hermonic s use kore NOD bar kore snod kora jabe 
// com is: (sqrt(n)/ln(sqrt(n)))*N
/* int lim = 12;

  for(int i=1; i<=lim; i++){
    for(int j=i; j<=lim; j+=i){
      sumOFdiv[j] += i;
    }
  }


  for(int i=1; i<=lim; i++){
    cout<<i<<": "<<sumOFdiv[i]<<endl;
  }
*/

/*
//3.using divisor list O(n)

	int n = 15;
	int snod = 0;

	for(int i=1; i<=n; i++){
		int contributionI = n/i;

		cout<< i << ": " << contributionI <<endl;

		snod += contributionI;
	}

	cout<<snod<<endl;

*/

 //4.using divisor pairs O(sqrt(n)) 
  //onek kom complexity
  int n = 15;
  int snod = 0;

  int sq = sqrt(n);

  // formula is: [n/k] - k * 2 + sq
  for(int i=1; i<=sq; i++){

  	int val = (n/i) - i; // pairs combination kore  // [N/k] - k * 2 + sq

    // [15/2] - 2  = 5 * 2 + 3 = 12 so..on

    cout << i << " : " << val <<endl;

  	snod+=val;
  }

  snod*=2; // A<B and A>B , A er jono cnt kore  a<b * 2 

  cout << snod << endl;

  snod+=sq; //  A == B ta ei khane + kortaci 

  cout<<snod<<endl;


/*

1 : (1,1) 
2 : (1,2) , ( 2 , 1)
3 : ( 1 , 3) ( 3 , 1 ) 
4 : ( 1 , 4 ), ( 2 , 2 ),( 4,1) ( 2 , 2 )
5 : ( 1 , 5) , ( 5 , 1) 
6 : ( 1 , 6 ) , ( 2 , 3 ) ( 3 , 2)( 6 , 1 ) // ( 3*2 = 6)

// divisor goler and bag foll gola laka hoice pair hisabe like 6/2 = 3 , 6/3=2

// ei khane 3 doroner pair acce (A<B) , ( A>B) , ( A == B) // ( A*B==N)
*/




  return 0;
}