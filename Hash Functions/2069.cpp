#include<bits/stdc++.h>
using namespace std;
int main(){

	vector<string> v {"abcdef", "bcdefa", "cdefab", "defabc"};
	
	
	for(const auto &c: v){
		int hashCode = 0;
		for(int i=0; i< c.length(); i++){
			int value = c[i];
			hashCode =  (hashCode + value*(i+1))%2069;
			hashCode %= 2069;
		}
		cout << c << " " << hashCode%2069 << "\n";
	}
	




	return 0;
}