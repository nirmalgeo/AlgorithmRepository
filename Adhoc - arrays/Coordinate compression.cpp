/*
Given an array a[] of size n, reassign integers to each value of a[]
such that the magnitude of each new value is no more than n, while the
relative order of each value as they were in the original array is
preserved. That is, if a[] is the original array and b[] is the result
array, then for every pair (i, j), the result of comparing a[i] < a[j]
will be exactly the same as the result of b[i] < b[j]. Furthermore,
no value of b[] will exceed the *number* of distinct values in a[].
In the following implementations, values in the range [lo, hi) will be
converted to integers in the range [0, d), where d is the number of
distinct values in the original range. lo and hi must be random access
iterators pointing to a numerical type that int can be assigned to.
Time Complexity: O(n log n) on the distance between lo and hi.
Space Complexity: O(n) auxiliary.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> v{1,30, 30, 7, 9, 8, 99, 99};
vector<double> d{0.5, -1.0, 3, -1.0, 20, 0.5};

template<class T>
void compress(vector<T> &v){
	int n = v.size();
	
	map<int, int> m;
	
	for(int i=0; i<n; i++)
		m[v[i]] = 0;
	
	auto x = m.begin();
	
	for(int i=0; x!= m.end(); x++){
		x->second = i++;
		cerr << x->first << " " << x->second << "\n";
	}
	
	// o(n log n)
	for(int i=0; i<n; i++)
		v[i] = m[v[i]];
}

int main(){

	compress(v);
	
	for(auto &c: v)
		cout << c << " ";
	compress(d);
	return 0;
	cout << "\n";
	for(auto &c: d)
		cout << c << " ";
	return 0;
}