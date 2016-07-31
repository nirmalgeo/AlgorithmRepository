#include<bits/stdc++.h>
using namespace std;
long long dp[5010];
int main(){

	string s;
	
	while(cin >> s && s!= "0"){
		
		memset(dp, 0 , sizeof dp);
		
		dp[0] = 1;
		
		int len = s.length();
		
		for(int i=1; i< len; i++){
			int temp = 0;
			temp = (s[i-1] - '0')*10;
			temp += (s[i] - '0');
			
			if(s[i] - '0')
				dp[i] = dp[i-1];
			
			if(temp <= 26 && temp > 9)
				dp[i] += dp[i-2 <  0? 0: i-2];
		}
		
		cout << dp[len-1] << "\n";
	}

	return 0;
}