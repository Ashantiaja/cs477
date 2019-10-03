// q1.cpp
// CS477 : hw4 : Question 1
// @Ash Y Cudiamat

#include <iostream>
#include <vector>
using namespace std;

/*
Implement in C++ an algorithm to rearrange elements of a given array of n real numbers so that all its 
negative elements precede all its positive elements. Your algorithm should be both time- and space- efficient.
Show how your algorithm works on the following input.
 */

template <typename T>
void almostQuicksort (T* input,
		      const unsigned int p,
		      const unsigned int r);

template <typename T>
unsigned int partition(T* input,
		       const unsigned int p,
		       const unsigned int r);


int main() {

  vector<float> input = {4, 3, -2, 0, 2, 9,
			   -1, 10, 0, 5, 23, -4};
  almostQuicksort(&input[0], 0, input.size());

  for(int i = 0; i < input.size(); i++) {
    cout << input[i] << " ";
  }
  cout << endl;

  return 0;
}

template <typename T>
void almostQuicksort (T* input,
		      const unsigned int p,
		      const unsigned int r) {
  if (p < r) {
    unsigned int q = partition(input, p, r);
    almostQuicksort(input, p, q-1);
    almostQuicksort(input, q+1, r);
  }
}

template <typename T>
unsigned int partition(T* input,
		       const unsigned int p,
		       const unsigned int r) {
  cout << "Partition call p:" << p << " r:" << r << endl;
  T pivotVal = input[r];
  unsigned int i = p-1;
  for(unsigned int j = p; j <= r-1; j++) {
    if (input[j] <= pivotVal) {
      i++;
      //swap input[i], input[j]
      T temp = input[i];
      input[i] = input[j];
      input[j] = temp;
    }
  } // end for

  T temp = input[i+1];
  input[i+1] = input[r];
  input[r] = input [i+1];
  return i+1;
}
