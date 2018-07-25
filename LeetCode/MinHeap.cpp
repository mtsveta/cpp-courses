// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
    int *heap; // pointer to array of elements in heap
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
    void minHeapify(int);
    // to extract the root which is the minimum element
    int extractMin();
    // decreases key value of key at index list_indx to new_val
    void decreaseKey(int i, int new_val);
    // returns the minimum key (key at root) from min heap
    int getMin() { return heap[0]; }
    // to delete a key stored at index list_indx
    void deleteKey(int i);
    // to inserts a new key 'k'
    void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    heap = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    heap[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && heap[parent(i)] > heap[i])
    {
       swap(&heap[i], &heap[parent(i)]);
       i = parent(i);
    }
}

// Decreases value of key at index 'list_indx' to new_val.  It is assumed that
// new_val is smaller than heap[list_indx].
void MinHeap::decreaseKey(int i, int new_val)
{
    heap[i] = new_val;
    while (i != 0 && heap[parent(i)] > heap[i])
    {
       swap(&heap[i], &heap[parent(i)]);
       i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return heap[0];
    }

    // Store the minimum value, and remove it from heap
    int root = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;
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
    if (l < heap_size && heap[l] < heap[i])
        smallest = l;
    if (r < heap_size && heap[r] < heap[smallest])
        smallest = r;
    if (smallest != i)
    {
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
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}