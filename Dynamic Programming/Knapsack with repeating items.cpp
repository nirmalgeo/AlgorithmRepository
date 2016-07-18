/*
13
5
10 8
8 6
5 3
10 6
1 0

Recurrence relation :-


F(w)= max{ F(w-wi)+vi , F(w-1) .... for wi <= w
	  max{  0 , w==0

*/
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

vector<pair<int, int>> data ;
int memo[1000];
vector<int> indexTable, indexValue;
int cnt = 0;
/*
int f(int i, int w){
	cnt++;
	
	if(w == 0) return 0;
	if(w < 0)  return 0;
	if(i < 0)  return 0;
	
	if(memo[i][w] != -1)
		return memo[i][w];

	int val=0;
	
	if(data[i].first <= w)
		val = max(val , data[i].second  + f(i , w- data[i].first));
	val = max(val , f(i-1, w));
	memo[i][w] = val;
	return val;
}
*/


int f(int w){
	cnt++;
	
	if(w==0) return 0;
	
	if(memo[w] != -1)
		return memo[w];
		
	int val = f(w-1);
	
	for(int i=0; i<data.size(); i++){
		if(data[i].first <= w){
			int k;
			k = data[i].second + f(w - data[i].first);
			if( k > val){
				val = k;
				indexTable[w] = i+1;
			}
		}
	}
		
	return memo[w] = val;
}
	
void backtrack(int w){
	if(w==0) return;
	indexValue.push_back(indexTable[w]);
	backtrack(w - data[indexTable[w]-1].first);
}	

int main(){

	int bagWeight;
	
	cin >> bagWeight;
	
	int n;
	cin>> n;
	
	for(int i=0; i<n; i++){
		int cost, weight;
		cin >> weight >> cost;
		data.push_back({weight, cost});
	}
	
	
	indexTable.resize(MAX);
	
	memset(memo, -1, sizeof memo);
	
	
	cout << "Max Cost : "  <<  f(bagWeight) << "\n";
	//cout << cnt <<"\n";
	
	backtrack(bagWeight);
	
	for(int i=0; i< indexValue.size(); i++)
		cout << "Item : " << indexValue[i] << " \n";

	return 0;
}