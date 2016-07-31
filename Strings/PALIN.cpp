// find the very next palindrome of a number ...huge digits
#include<bits/stdc++.h>
using namespace std;

int all9s(string s){
	
	int l = s.length(); 
	for(int i=0; i<l; i++)
		if(s[i] != '9')
			return 0;
	
	return 1;
}

void modify(string &s){

	int n = s.length();
	int mid = n/2;
	bool leftsmaller = false;
	
	int i = mid-1;
	int j = (n&1)? mid+1: mid;
	
	while(i>=0 && s[i] == s[j])
		i--, j++;
	
	if( i<0 || s[i] < s[j])
		leftsmaller = true;
		
	while(i >= 0){
		s[j] = s[i];
		j++;
		i--;
	}
	
	if(leftsmaller == true){
		int carry = 1;
		i = mid - 1;
		
		if(n&1){
			int value = s[mid] - '0';
			value += carry;
			carry = value/10;
			value %= 10;
			s[mid] = value + '0';
			j = mid +1;
		}
		else
			j = mid;
		
		
		while(i>=0){
			int value = s[i] - '0';
			value += carry;
			carry = value/10;
			value %= 10;
			s[i] = value + '0';
			s[j++] = s[i--];
		}
	}
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		if(all9s(s)){
			cout << "1";
			for(int i=1; i<s.length(); i++)
				cout << "0";
			cout << "1\n";
		}
		else{
			modify(s);
			cout << s << "\n";
		}
	}



	return 0;
}