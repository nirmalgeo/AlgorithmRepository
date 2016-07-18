#include<bits/stdc++.h>
using namespace std;

int price[25][25];
int memo[210][25];
int m , c;

int shop(int money , int g){
	
	if(money < 0) return -100000000;
	
	if(g == c) return (m- money);
	
	int& ans = memo[money][g];
	if(ans != -1) return ans;
	
	for(int k=1; k<= price[g][0]; k++)
		ans = max(ans, shop( money - price[g][k], g+1));
	
	return ans;
}



int main(){

	int t;
	scanf("%d", &t);
	
	while(t--){
			
		scanf("%d %d", &m, &c);
		
		for(int i=0; i<c; i++){
			int k;
			scanf("%d", &k);
			price[i][0] = k;
			for(int j=1; j<=k; j++)
				scanf("%d", &price[i][j]);
		}
		memset(memo, -1 , sizeof memo);
		
		int ans = shop(m, 0);
		if(ans < 0)
			cout << "no solution\n";
		else
			cout << ans << "\n";
	
	}

	return 0;
}