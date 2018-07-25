//
// Created by Svetlana Matculevich on 04/09/2017.
//
#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr){}
};

class Solution{

public:

    void print_list(list<int>& l){
        auto it = begin(l);
        for_each(begin(l), end(l), [&](int elem) {
            auto space = ((++it) != end(l)) ? " -> " : "";
            cout << elem << space;
        });
        cout << endl;
    }
    void merdeKlist(vector<list<int>>& lists, int lists_num, list<int>& merged_list){

        int i = 0, j = lists_num - 1;

        while (lists_num){
            cout << "list_indx-th list: "; print_list(lists[i]);
            cout << "j-th list: "; print_list(lists[j]);

            lists[i].merge(lists[j]);
            cout << "list_indx-th list (merged): "; print_list(lists[i]);
            i++;
            j--;
            if (i >= j) {lists_num = j; i = 0;}
        }
    }

};
int main(){

    Solution sol;
    /*
    Node* list1;
    Node* list2;

    vector<Node*> lists;
    lists[0]->data =
    lists[0]->next = new Node{};
    */


    int k = 3; // number of lists
    int n = 4; // number of elements in the list
    vector<list<int>> stdLists(k);
    stdLists[0] = list<int> {1, 3, 5, 7};
    stdLists[1] = list<int> {2, 4, 6, 8};
    stdLists[2] = list<int> {0, 9, 10, 11};

    // merge of 2 sorted lists is 0(n)
    // greedy algorithm O(k * log(k))
    list<int> mergedList;
    sol.merdeKlist(stdLists, k, mergedList);
    /*
     *
     * int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list

    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);
     */
    return 0;
}