/* codeforces */
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int cnt[N];
long long f[N];

int main(){

	int n;
	scanf("%d",&n);
	for(int i = 0; i < n ; i++) {
		int foo;
		scanf("%d", &foo);
		cnt[foo]++;
	}
	
	f[0] = 0;
	for(int i = 1; i < N ; i++) {
		f[i] = (long long) i * cnt[i];
		if( i-2 >= 0)
			f[i] += f[i-2];
		
		f[i] = max(f[i] , f[i-1]);
	}
	
	cout << f[N-1];
	
	return 0;
}