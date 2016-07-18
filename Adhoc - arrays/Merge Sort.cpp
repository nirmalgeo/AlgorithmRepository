#include<bits/stdc++.h>
using namespace std;
vector<int> v{5,4,3,3,2,1};


template<class It, class Compare>
void mergesort(It lo, It hi, Compare comp){
	if(hi - lo < 2) return;
	
	It mid = lo + (hi- lo - 1)/2, a = lo, c = mid+1;
	
	mergesort(lo, mid+1, comp);
	mergesort(mid+1, hi, comp);
	
	typedef typename std::iterator_traits<It>::value_type T;
	
	T *buff = new T[hi - lo], *b = buff;
	
	while( a<= mid && c < hi)
		*(b++) = comp(*c, *a)? *(c++) : *(a++);
	
	if( a > mid){
		for(It k = c; k < hi; k++)
			*(b++) = *k;
	}
	else{
		for(It k = a; k <= mid ; k++)
			*(b++) = *k;
	}
	
	for(int i= (hi - lo - 1); i>=0; i--)
		*(lo+i) = buff[i];
		
	delete[] buff;
}


template<class It>
void mergesort(It lo, It hi){
	typedef typename std::iterator_traits<It>::value_type T;
	mergesort(lo, hi, std::less<T>());
}

int main(){

	mergesort(v.begin(), v.end());
	
	for(auto &c:  v)
		cout << c << " ";


	return 0;
}


