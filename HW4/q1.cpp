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
void algorithm (T* input, const unsigned int p, const unsigned int r);

template <typename T>
void swap(T* input, int a, int b) {
  T temp = input[a];
  input[a] = input[b];
  input[b] = temp;
}


int main() {

  vector<float> input = {4, 3, -2, 0, 2, 9,
			   -1, 10, 0, 5, 23, -4};
  //almostQuicksort(&input[0], 0, input.size());
  algorithm(&input[0], 0, input.size());

  for(int i = 0; i < input.size(); i++) {
    cout << input[i] << " ";
  }
  cout << endl;

  return 0;
}

template <typename T>
void algorithm (T* input, const unsigned int p, const unsigned int r) {
  int i, j;
  i = p;
  j = r-1;
  while (i < j) {
    //i+, j+, keep j, switch i)
    if( (input[i] > 0) && (input[j] > 0) ) {
      j--;
      //swap i?
      swap(input, i, (j-1));
    }
    //i-, j-, keep i, switch j
    else if( (input[i] < 0) && (input[j] < 0) ) {
      i++;
      swap(input, j, (i+1));
    }
    //i+, j-, switch both
    else if( (input[i] > 0) && (input[j] < 0) ) {
      swap(input, i, j);
      i++;
      j--;
    }
    else { // keep both or just move on
      i++; j--;
    }

  } // end while
}
