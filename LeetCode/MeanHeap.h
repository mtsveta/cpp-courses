//
// Created by Svetlana Matculevich on 05/09/2017.
//

#ifndef LEETCODE_MEANHEAP_H
#define LEETCODE_MEANHEAP_H
#include "bits/stdc++.h"

// A class for Min Heap
class MinHeap
{
    vector<int> heap; // vector representing the heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
    int parent(int i) const { return (i-1)/2; }
    // to get index of left child of node at index list_indx
    int left(int i) const { return (2*i + 1); }
    // to get index of right child of node at index list_indx
    int right(int i) const { return (2*i + 2); }

    // to heapify a subtree with root at given index
    void minHeapify(int i);
    // to extract the root which is the minimum element
    int extractMin();
    // to fix min heap property
    void fixMinProperty(int i);
    // decreases key value of key at index list_indx to new_val
    void decreaseKey(int i, int new_val);
    // returns the minimum key (key at root) from min heap
    int getMin() { return heap[0]; }
    // to delete a key stored at index list_indx
    void deleteKey(int i);
    // to inserts a new key 'k'
    void insertKey(int k);

    vector<int> getHeapVector(){return heap;}
    int getHeapSize(){return heap_size;}
};

#endif //LEETCODE_MEANHEAP_H
