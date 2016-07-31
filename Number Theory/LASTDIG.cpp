#include<bits/stdc++.h>
using namespace std;
// modular exponentiation to calculate last digit of a^b
long long modexp(long long a, long long b, long long mod){
	
	long long ans = 1;
	
	while(b){

		if(b&1)
			ans = (ans*a)%mod;
			
		b = b >> 1;
		a = (a*a)%mod;
	}

	return ans;
}
int main(){

	int t;
	cin >> t;
	
	while(t--){
		long long a, b;
		cin >> a >> b;
		cout << modexp(a,b,10) << "\n";
	}


	return 0;
}