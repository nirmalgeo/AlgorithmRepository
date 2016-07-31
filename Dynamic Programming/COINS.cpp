/*

In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?

Input

The input will contain several test cases (not more than 10). Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000. It is the number written on your coin.

Output

For each test case output a single line, containing the maximum amount of American dollars you can make.

*/

#include<bits/stdc++.h>
using namespace std;

map<long long, long long> dp;

long long func(long long n){
	if(n==0) return 0;

	if(dp[n]!=0) return dp[n];
	
	long long temp = func(n/2) + func(n/3) + func(n/4);
	
	long long maxx  = max(temp, n);
	dp[n] = maxx;
	
	return dp[n];
}



int main(){
	
	long long n;
	
	while(cin >> n){
	
		cout << func(n) << "\n";
	
	}


	return 0;
}