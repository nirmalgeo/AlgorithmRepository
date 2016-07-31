// kth number cube which ends in 888
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int t;
	cin >> t;
	
	while(t--){
		long long k;
		cin >> k;
		
		long long ans = 192 + (k-1)*250;
	
		cout << ans << "\n";
	}



	return 0;
}