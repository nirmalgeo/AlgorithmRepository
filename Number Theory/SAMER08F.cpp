// number of squares in grid

// 1^2 + 2^2 + 3^2 ... = n*(n+1)*(2n+1)6

#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n;
	
	while(cin >> n){
		if(n==0)break;
		
		cout << n*(n+1)*(2*n+1)/6 << "\n";
	}




	return 0;
}