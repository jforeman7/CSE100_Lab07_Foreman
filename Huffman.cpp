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

	if (r < A_size && A[r] > A[smallest])
		smallest = r;

	// If A[i] is smallest, then done.
	// Otherwise we must swap and then start again, as the max heap property may be violated.
	if (smallest != i)
	{
		swap(A[i], A[smallest]);

		MaxHeapify(A, A_size, smallest);
	}
}

void BuildMinHeap(int* A, int A_size)
{
	// Ensures smallest value is at root, to satisfy max heap property.
	for(int i = A_size / 2 - 1; i >= 0; i--)
		MinHeapify(A, A_size, i);
}
