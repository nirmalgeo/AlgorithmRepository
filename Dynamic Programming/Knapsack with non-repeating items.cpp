/*
12
6
2 1
10 8
8 6
5 5
10 6
1 0

 Top down
 ==========
 
 F(w) = 0 , w == 0
      
 F(w) =   max { f1, f2 }
 
	
		f1 ---> F(i, w-wi)+vi     ... for all wi<=w-wi
		f2 ---> F(i-1, w)


 Bottom up approach below:- 

*/


#include<bits/stdc++.h>
using namespace std;
int dp[100][10000];
int bagWeight, n;

vector<pair<int,int>> data;

vector<int> items;


void backtrack(int w, int i){
	if(w==0 || i==0) return;
	if(dp[w][i] == dp[w][i-1]) backtrack(w, i-1);
	else{
		items.push_back(i);
		backtrack(w - data[i-1].first, i-1);
	}
}

int main(){
	
	cin >> bagWeight;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int weight, cost;
		cin >> weight >> cost;
		data.push_back({weight, cost});
	}
	
	for(int w=1; w<= bagWeight; w++){
		for(int i=1; i<= data.size(); i++){
			dp[w][i] = dp[w][i-1];
			if(data[i-1].first <= w)
				dp[w][i] = max(dp[w][i], dp[w- data[i-1].first][i-1] + data[i-1].second);
		}
	}
	cout << "\nMax weight : " << dp[bagWeight][n];
	
	backtrack(bagWeight, n);
	
	cout << "\nItems used : " << items.size() << "\n";
	for(int i=0; i<items.size(); i++)
		cout << items[i] << " " ;

	return 0;
}