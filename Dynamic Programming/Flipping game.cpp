/* Kadane's algorithm  - maximal sub array sum */

#include <bits/stdc++.h>
using namespace std;
const int N= 110;

int flip[N];
int arr[N];

int main(){
	int n;
	scanf("%d", &n);
	int totalones = 0;
	for( int i=0; i < n ; i++) {
		scanf("%d", &arr[i]);
		
		if(arr[i]) {
			flip[i] = -1;
			totalones++;
		}
		
		else flip[i] = 1;
	}
	
	int maxx = 0 , curr = 0;
	
	maxx = flip[0];
	curr = flip[0];
	
	for(int i=1; i< n; i++ ) {
		curr = max(flip[i] , flip[i] + curr);
		maxx = max(curr, maxx);
	}

	cout << maxx + totalones ;



	return 0;
}