#include<bits/stdc++.h>
using namespace std;
bool reachable[25][210];
int price[25][25];
int g, money, M, C;

int main(){

	int t;
	scanf("%d", &t);
	
	while(t--){
		
		scanf("%d %d", &M, &C);
		
		for(int i=0; i<C; i++){
			scanf("%d", &price[i][0]);
			
			for(int j=1; j<= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		
		memset(reachable, false , sizeof reachable);
		
		for(int i=1; i<= price[0][0]; i++)
			if(M - price[0][i] >= 0)
				reachable[0][M - price[0][i]] = true;
				
		for(int i=1; i<C; i++)
			for(int j=0; j< M; j++)
				if(reachable[i-1][j])
					for(int k=1; k<= price[i][0]; k++)
						if( j - price[i][k] >= 0)
							reachable[i][j- price[i][k]] = true;
							
		int ans;
		
		for(ans = 0; ans<= M && !reachable[C-1][ans]; ans++);
		
		
		if(ans == M+1)	cout << "no solution\n";
		else	cout << M-ans << "\n";
	}

	return 0;
}