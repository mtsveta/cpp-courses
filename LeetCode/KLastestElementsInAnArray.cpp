// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
// Utility function
void print_vector(const vector<int>& s, int k){
    int i = 0;
    for (auto it = begin(s); i < k; it++) {
        auto space = ((++i) != k) ? ", " : "";
        cout << *it << space;
    }
    cout << endl;
}
void print_vector(vector<int>& s){
    auto it = begin(s);
    for_each(begin(s), end(s), [&](int elem) {
        auto space = ((++it) != end(s)) ? ", " : "";
        cout << elem << space;
    });
    cout << endl;
}
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
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Driver program to test above functions
int main()
{
    // Ist method using STL algorithms
    vector<int> v = {1, 23, 12, 9, 30, 2, 50};
    //vector<int> v = {10, 9, 8, 7, 6, 5, 1};

    auto descended_sort = [](int el1, int el2){return el1 > el2;};
    int k = 3;
    vector<int> k_largest_in_v(k, 0);

    if (is_sorted(begin(v), end(v), descended_sort))
        copy(begin(v), begin(v) + k, begin(k_largest_in_v));
    else
        partial_sort_copy(begin(v), end(v), begin(k_largest_in_v), end(k_largest_in_v), descended_sort);

    cout << "k largest elem:" << endl;
    print_vector(k_largest_in_v);

}//
// Created by Svetlana Matculevich on 05/09/2017.
//

