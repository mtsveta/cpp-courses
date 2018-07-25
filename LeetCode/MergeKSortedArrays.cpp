// C++ program to merge k sorted arrays of size n each.
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// A min heap node
struct MinHeapNode
{
    int element; // The element to be stored
    int list_indx; // index of the array from which the element is taken
    int next_array_elem_to_pick; // index of the next element to be picked from array
};

// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);

void print_vector(vector<int>& s);

// A class for Min Heap
class MinHeap
{
    MinHeapNode *harr; // pointer to array of elements in heap
    int heap_size; // size of min heap
public:
    // Constructor: creates a min heap of given size
    MinHeap(MinHeapNode a[], int size);

    // to heapify a subtree with root at given index
    void MinHeapify(int );

    // to get index of left child of node at index list_indx
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index list_indx
    int right(int i) { return (2*i + 2); }

    // to get the root
    MinHeapNode getMin() { return harr[0]; }

    // to replace root with new node x and heapify() new root
    void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); }
};

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(const vector< vector<int> >& v, int k, vector<int>& merged_v)
{
    // Create a min heap with k heap nodes.  Every heap node
    // has first element of an array
    MinHeapNode *harr = new MinHeapNode[k];
    int n = merged_v.size() / k;

    for (int i = 0; i < k; i++) {
        harr[i].element = v[i][0];              // Store the first element
        harr[i].list_indx = i;                  // Index of array
        harr[i].next_array_elem_to_pick = 1;    // Index of next element to be stored from array (the first ones is initialized to 1)
    }
    MinHeap hp(harr, k); // Create the heap

    // Now one by one get the minimum element from min
    // heap and replace it with next element of its array
    for (int count = 0; count < n*k; count++)
    {
        // Get the minimum element and store it in output
        MinHeapNode root = hp.getMin();
        merged_v[count] = root.element;

        // Get the next element that will replace curren root of heap.
        // The next element belongs to same array as the current root.
        if (root.next_array_elem_to_pick < n) { // Until we have reached the end of the array
            root.element = v[root.list_indx][root.next_array_elem_to_pick];
            root.next_array_elem_to_pick += 1;
        }
        // If root was the last element of its array (so that it goes all the way down)
        else root.element =  INT_MAX; //INT_MAX is for infinite

        // Replace root with next element of array
        hp.replaceMin(root);
    }
}

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;  *x = *y;  *y = temp;
}

void print_vector(vector<int>& s){
    auto it = begin(s);
    for_each(begin(s), end(s), [&](int elem) {
        auto space = ((++it) != end(s)) ? ", " : "";
        cout << elem << space;
    });
    cout << endl;
}

// Driver program to test above functions
int main()
{
    // Change n at the top to change number of elements
    // in an array
    int n = 4;
    int k = 3;
    vector< vector<int> > v{{2, 6, 12, 34},
                       {1, 9, 20, 1000},
                       {23, 34, 90, 2000}};
    vector<int> merged_v(k*n, 0);
    mergeKArrays(v, k, merged_v);
    cout << "Merged array is " << endl;
    print_vector(merged_v);

    return 0;
}