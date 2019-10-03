//Mod Merge Sort

#include <iostream>

template <typename T>
void mergesort(T* array, const int n);

template <typename T>
void displayArray(T* array, const int n);

int main(void) {
  const int size = 15;
  char example[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G',
		    'E', 'X', 'A', 'M', 'P', 'L', 'E'};

  int intExample[] = {5, 4, 3, 2, 6,
		      7, 12, 13, 23, 0,
		      9, 10, 11, 1, 8};

  mergesort(intExample, size);
  mergesort(example, size);

  std::cout << "Char sorted example: ";
  displayArray(example, size);
  std::cout << "Int sorted example: ";
  displayArray(intExample, size);
  
  return 0;
}

template <typename T>
void mergesort(T* array, const int n) {

  int unequalMultiple = 1;
  
  // 0 to n-1
  // m by m merge m -> 0 to n-1?
  for(int m = 1; m < n/2; m *= 2) {
    //std::cout << m << std::endl;
    //Go through array, divide and re-merge?
    for(int i = 0; i < n; i += (2 * m)) {
      // Merge
      int first1 = i;
      int first2 = i+m;
      int last1 = i+m-1;
      int last2 = i+(2*m)-1;
      int storageIndex = 0;
      const int storageSize = 2*m;
      T storageArray[storageSize];

      if (last2 >= n)
	last2--;
		
      // copy into storage array in sorted order
      while( (first1 <= last1) && (first2 <= last2) ) {
	if(array[first1] <= array[first2]) {
	  storageArray[storageIndex++] = array[first1++];
	}
	else
	  storageArray[storageIndex++] = array[first2++];
      } // end while

      // copy remains of first array into storage
      while (first1 <= last1) {
	storageArray[storageIndex++] = array[first1++];
      }
      // alternatively, copy remains of second array into storage
      while (first2 <= last2) {
	storageArray[storageIndex++] = array[first2++];
      }

      // Copy storage array into original place in array
      storageIndex = 0; // 0 to i+2m
      for(int a = i; a < i + storageSize; a++, storageIndex++) {
	array[a] = storageArray[storageIndex];
      }
      
    } // end for
        unequalMultiple = m*2;
  } // end for

  // Last merge m by x
  //first1 = 0, last1 = m
  //first2 = m+1, last2 = n-1
  int f1 = 0,
    l1 = unequalMultiple-1,
    f2 = unequalMultiple,
    l2 = n-1,
    tIndex = 0;
  //n is tArray size
  T tArray[n];

  //  displayArray(array, n);
  //  std::cout << array[unequalMultiple+1] << std::endl;

  while ( (f1 <= l1) && (f2 <= l2) ){
    if( array[f1] <= array[f2] )
      tArray[tIndex++] = array[f1++];
    else
      tArray[tIndex++] = array[f2++];
  }
  //displayArray(tArray, tIndex+1);
  while (f1 <= l1) {
    tArray[tIndex++] = array[f1++];
  }
  while (f2 <= l2) {
    tArray[tIndex++] = array[f2++];
  }

  for(int i = 0; i < n; i++) {
    array[i] = tArray[i];
  }
  
  return;
}

template <typename T>
void displayArray(T* array, const int n) {
  for(int i = 0; i < n; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}
