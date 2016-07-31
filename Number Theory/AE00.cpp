//count no. of rectangles from n(1x1) units

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	
	cin >> n;
	
	int ans = 0;
	
	//squares
	ans = sqrt(n);
	
	//rectangles
	for(int i=1; i<=sqrt(n); i++)
		for(int j= i+1; i*j <=n; j++)
			ans++;
			
	cout << ans;


	return 0;
}