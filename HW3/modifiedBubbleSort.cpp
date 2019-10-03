//Mod Bubble Sort
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void bubbleSort(T* sortArray, const int n);

int comparisons = 0;

int main(void) {
  char testArray[] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'};

  bubbleSort(testArray, 12);

  for(int i = 0; i < 12; i++)
    std::cout << testArray[i];
  std::cout << std::endl << "Comparisons for Example: " <<  comparisons << std::endl;
  return 0;
}

template <typename T>
void bubbleSort(T* sortArray, const int n) {
  bool sorted = false;
  bool leftToRight = true;
  
  while(!sorted) {
    sorted = true;
    
    if(leftToRight) {
      for(int i = 0; i < n-1; i++) {
	comparisons++;
	if(sortArray[i] > sortArray[i+1]) {
	  sorted = false;
	  // Swap
	  T temp = sortArray[i];
	  sortArray[i] = sortArray[i+1];
	  sortArray[i+1] = temp;
	}
      } // End for
      leftToRight = false;
    }
    
    else { // Go from Right to Left
      for(int i = n-1; i > 0; i--) {
	comparisons++;
	if(sortArray[i] < sortArray[i-1]) {
	  sorted = false;
	  // Swap!
	  T temp = sortArray[i];
	  sortArray[i] = sortArray[i-1];
	  sortArray[i-1] = temp;
	}
      } // End for
      leftToRight = true;
    }
  } // End while(!sorted)

  return;

  } 
