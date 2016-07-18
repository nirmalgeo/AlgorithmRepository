#include <bits/stdc++.h>
using namespace std;

const int N = 4005;

int dp[N];
int n , a , b , c;
vector<int> items;

int main(){

	
	scanf("%d %d %d %d" , &n , &a, &b , &c);
	
	items.push_back(a);
	items.push_back(b);
	items.push_back(c);
	
	for(int i=0; i<=n; i++){
		if(dp[i] == 0 && i!=0) continue;
		for(int j=0; j< items.size(); j++){
			if( i + items[j]  <= n)
				dp[i + items[j]] = max( dp[i + items[j]], dp[i] + 1 );
		}
	}
	
	cout << dp[n];
	
	


	return 0;
}