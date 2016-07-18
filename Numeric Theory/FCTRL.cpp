// number of zeros(ending) in fact!
#include<bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin >> t;
	
	while(t--){
	
		long long n;
		cin >> n;
		
		long long count = 0;
		for(long long i=5;  (n/i) >= 1; i*= 5)
			count += (n/i);
			
		cout << count << "\n";
	
	}


	return 0;
}