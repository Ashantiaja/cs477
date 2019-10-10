#include <iostream>
#include <vector>
using namespace std;
/*
   Implement in C/C++ an algorithm that checks if an array of n elements is a max-heap and determine its running time. The algorithm should print “YES, heap” or “Not a heap”, depending on the outcome. Show how your algorithm works on the following arrays A = [16  14  10  8  7  9  3  2  4  1] and B = [10  3  9  7  2  11  5  1  6].
 */

template <typename T> 
void CHECK_MAX_HEAP(vector<T> heap, int i, int &runningTime, bool &isMaxHeap = true);
inline int parentIndex(int i) { return i/2; }
inline int leftIndex(int i) { return 2*i; }
inline int rightIndex(int i) { return (2*i)+1; }

int main() {
  vector<int> A = {16, 14, 10, 8, 7,
		   9, 3, 2, 4, 1};
  vector<int> B = {10, 3, 9, 7, 2, 11,
		   5, 1, 6};

  bool AMaxHeap = true;
  bool BMaxHeap = true;
  int ARunningTime = 0;
  int BRunningTime = 0;

  cout << "Check A" << endl;
  CHECK_MAX_HEAP(A, 1, ARunningTime, AMaxHeap);
  if(AMaxHeap)
    cout << "Yes, this is a heap." << endl;
  cout << "Running time for A: " << ARunningTime << endl;

  cout << "Check B" << endl;
  CHECK_MAX_HEAP(B, 1, BRunningTime, BMaxHeap);
  if(BMaxHeap)
    cout << "Yes, this is a heap." << endl;
    cout << "Running time for B: " << BRunningTime << endl;
  
  return 0;
}

template <typename T>
void CHECK_MAX_HEAP(vector<T> heap, int i, int &runningTime, bool &isMaxHeap) {
  // Check if i is a leaf/out of array bounds

  if( i >= heap.size() ) {
    return;
  }

  // Start from leaves and go up heap
  CHECK_MAX_HEAP(heap, leftIndex(i), runningTime, isMaxHeap);
  CHECK_MAX_HEAP(heap, rightIndex(i), runningTime, isMaxHeap);

  // Check that parent is lesser than current node, meaning the
  // heap is not a max heap
  // i starts from 1, bUT the heap starts from 0, hence i-1
  runningTime++;
  if( heap[ parentIndex(i-1) ] < heap[i-1] ) {
    isMaxHeap = false;
    cout << "Not a heap." << endl;
  }
} // End void CHECK_MAX_HEAP
