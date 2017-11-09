// Jeff Foreman
// CSE 100 03L
// Lab 07: Huffman Codes
// 30 Oct 2017
// Changed my heapsort code to create a MinHeap.

#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility> // For Swap.

using namespace std;

// Must add 1, to account for change in index start from textbook pseudocode.
int Parent(int i) { return i / 2; }
int Left(int i) { return 2 * i + 1; }
int Right(int i) { return 2 * i + 2; }

void MinHeapify(int* A, int A_size, int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest;

	// Look for the smallest value, and store its index value in "smallest".
	if (l < A_size && A[l] < A[i])
		smallest = l;
	else
		smallest = i;

	if (r < A_size && A[r] < A[smallest])
		smallest = r;

	// If A[i] is smallest, then done.
	// Otherwise we must swap and then start again, as the max heap property may be violated.
	if (smallest != i)
	{
		swap(A[i], A[smallest]);

		MinHeapify(A, A_size, smallest);
	}
}

void BuildMinHeap(int* A, int A_size)
{
	// Ensures smallest value is at root, to satisfy max heap property.
	for(int i = A_size / 2 - 1; i >= 0; i--)
		MinHeapify(A, A_size, i);
}

void HeapSort(int* A, int A_size)
{
	BuildMinHeap(A, A_size);

	for(int i = A_size - 1; i >= 1; i--)
	{
		swap(A[0], A[i]);

		//Largest value is now at the end, so "cut" off that node.
		A_size--;

		// Re-Heap.
		MinHeapify(A, A_size, 0);
	}
}


int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];

  // Read in the sequence
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  HeapSort(Sequence, arraySize);

  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;

  // Free allocated space
  delete[] Sequence;
}
