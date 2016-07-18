#include<bits/stdc++.h>
using namespace std;

int rand32(){
	return (rand() & 0x7fff) | ((rand() & 0x7fff) << 15);
}


template<class It>
It rand_partition(It lo , It hi){
	swap(*(lo+rand32() % (hi-lo)), *(hi-1));
	
	typename std::iterator_traits<It>::value_type mid = *(hi-1);
	
	It i = lo - 1;
	
	for(It j = lo ; j < hi; j++){
		if( *j <= mid )
			swap( *(++i), *j);
	}

	return i;
}


template<class It>
void nth_element2(It lo, It n, It hi){
	for(;;){
		It k = rand_partition(lo , hi);
		if( n < k )
			hi = k;
		else if( n > k)
			lo = k+1;
		else return;
	}
}


int main(){
	vector<int> v{10, 1, 2,5, 3,4,6,7,8,9};
	
	//nth_element(v.begin(), v.begin() + 5 , v.end());
	random_shuffle(v.begin() , v.end());

	
	nth_element2(v.begin(), v.begin() + 5, v.end());
	
	
	for(auto &c: v)
		cout << c << " ";
	
	
	
	
	return 0;	
}