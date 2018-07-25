//
// Created by Svetlana Matculevich on 05/09/2017.
//

#include "MeanHeap.h"

using namespace std;

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    heap.resize(cap);
}


void MinHeap::fixMinProperty(int i){
    // Fix the min heap property if it is violated
    while (i != 0 && heap[parent(i)] > heap[i])
    {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}
// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity) {cout << "\nOverflow: Could not insertKey\n"; return;}

    // Insert the new key at the end
    int i = heap_size;
    heap[i] = k;
    // Increase the size of the heap
    heap_size++;
    // Fix the min heap property if it is violated
    fixMinProperty(i);
}

// Decreases value of key at index 'list_indx' to new_val.
void MinHeap::decreaseKey(int i, int new_val)
{
    // Assign new value (assuming that new_val is smaller than heap[list_indx])
    heap[i] = new_val;
    // Fix the min heap property if it is violated
    fixMinProperty(i);
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    // check limit cases
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return heap[0];
    }

    // Store the minimum value, and remove it from the heap
    int root = heap[0];
    // Move the last element to the root place
    heap[0] = heap[heap_size-1];
    // Decrease the heap size
    heap_size--;
    // Heapify
    minHeapify(0);

    return root;
}
// This function deletes key at index list_indx. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    // We always have to control that we are not beoynd the heap size!!!
    if (l < heap_size && heap[l] < heap[i])
        smallest = l;
    if (r < heap_size && heap[r] < heap[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}