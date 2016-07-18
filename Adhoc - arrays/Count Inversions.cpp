//  count inversions 
/*  how far (or close) the array is from being sorted
	but is *not* the same as the minimum number of swaps required to sort the array.

	sorted array --> ans =0
    decreasing array  --> max val ;	
*/


#include<bits/stdc++.h>
using namespace std;


template<class It> long long inversions(It lo, It hi) {
  if (hi - lo < 2) return 0;
  It mid = lo + (hi - lo - 1) / 2, a = lo, c = mid + 1;
  long long res = 0;
  res += inversions(lo, mid + 1);
  res += inversions(mid + 1, hi);
  typedef typename std::iterator_traits<It>::value_type T;
  T *buf = new T[hi - lo], *ptr = buf;
  while (a <= mid && c < hi) {
    if (*c < *a) {
      *(ptr++) = *(c++);
      res += (mid - a) + 1;
    } else {
      *(ptr++) = *(a++);
    }
  }
  if (a > mid) {
    for (It k = c; k < hi; k++)
      *(ptr++) = *k;
  } else {
    for (It k = a; k <= mid; k++)
      *(ptr++) = *k;
  }
  for (int i = hi - lo - 1; i >= 0; i--)
    *(lo + i) = buf[i];
  delete[] buf;
  return res;
}


int main(){

	int a[] = {6, 9, 1, 14, 8, 12, 3, 2};
	long long ans = inversions(a, a + 8);	
	assert(ans == 16);
	cout << ans << "\n";
	
	vector<int> v{1,2,3,5,4};
	
	ans = inversions(v.begin(), v.end());
	
	cout << ans << "\n";

	return 0;
}