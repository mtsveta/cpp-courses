#include <iostream>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

void addElement(list<int>& sortedList, const int& newElement);

int main(){

    // Insertion into sorted linked list
    // Insertion osrting

    list<int> sortedList;
    addElement(sortedList, 10);
    addElement(sortedList, 7);
    addElement(sortedList, 3);
    addElement(sortedList, 1);
    addElement(sortedList, 9);
    addElement(sortedList, 11);

    /*
    // Union and intersection of the lists
    list<int> list1({10, 15, 4, 20}); // n
    list<int> list2({8, 4, 2, 10}); // m
    print_list(list1);
    print_list(list2);
    cout << endl;

    alternative_insert(list1, list2);

    list1.clear();
    list2.clear();

    list1 = {1, 2, 3};
    list2 = {4, 5, 6, 7, 8};

    alternative_insert(list1, list2);


    list<char> listOfChars1({'g', 'e', 'e', 'k', 's', 'a'});
    list<char> listOfChars2({'g', 'e', 'e', 'k', 's', 'b'});
    cout << compare(listOfChars1, listOfChars2) << endl;

    listOfChars1.clear();
    listOfChars2.clear();
    listOfChars1 = {'g', 'e', 'e', 'k', 's', 'a'};
    listOfChars2 = {'g', 'e', 'e', 'k', 's'};
    cout << compare(listOfChars1, listOfChars2) << endl;

    listOfChars1.clear();
    listOfChars2.clear();
    listOfChars1 = {'g', 'e', 'e', 'k', 's'};
    listOfChars2 = {'g', 'e', 'e', 'k', 's'};
    cout << compare(listOfChars1, listOfChars2) << endl;

    list<int> listsUnion;
    list<int> listsIntersection;


    list1.clear();
    list2.clear();

    list1 = list<int>{10, 15, 4, 20};
    list2 = list<int>{8, 4, 2, 10};

    print_list(list1);
    print_list(list2);

    union_of_lists_with_hashing(list1, list2, listsUnion);
    cout << "union with hashing: " << endl;
    print_list(listsUnion);

    intersection_of_lists_with_hashing(list1, list2, listsIntersection);
    cout << "intersection with hashing: " << endl;
    print_list(listsIntersection);

    list1.clear();
    list2.clear();

    list1 = list<int>{10, 15, 4, 20};
    list2 = list<int>{8, 4, 2, 10};

    // Merge sort
    list1.sort();
    list2.sort();

    cout << "sorted: " << endl;
    print_list(list1);
    print_list(list2);
    cout << endl;

    listsUnion.clear();
    listsIntersection.clear();

    // Union O(n + m)
    union_of_lists(list1, list2, listsUnion);
    cout << "union: " << endl;
    print_list(listsUnion);

    intersection_of_lists(list1, list2, listsIntersection);
    cout << "intersection: " << endl;
    print_list(listsIntersection);

    */
    // With Hash Tables checking for the existing element 0(1)
    return 0;

};



void print_list(list<int>& l){
    auto it = begin(l);
    for_each(begin(l), end(l), [&](int elem) {
        auto space = ((++it) != end(l)) ? " -> " : "";
        cout << elem << space;
    });
    cout << endl;
}
void addElement(list<int>& sortedList, const int& newElement){

    if (sortedList.empty())
        sortedList.emplace_front(newElement);
    else{
        auto greater_then = [&newElement](int n){
            return n > newElement;
        };
        auto it = find_if(begin(sortedList), end(sortedList), greater_then);
        if (it != end(sortedList))
            if (it == begin(sortedList))
                sortedList.emplace_front(newElement);
            else
                sortedList.emplace(it--, newElement);
        else
            sortedList.emplace_back(newElement);

    }
    cout << "result of insetion: " << endl;
    print_list(sortedList);
}

void alternative_insert(list<int>& list1, list<int>& list2){

    // Alternate insert
    auto it1 = begin(list1);
    auto it2 = begin(list2);
    auto n = list1.size();
    //for (auto i = 0; i < n; i++){
    for (; it1 != end(list1);){
        it1++;
        //if (it1 == end(list1) && !list2.empty()){
        //    list1.emplace_back(*(it2));
        //}
        if (!list2.empty()) {
            cout << "inserting " << *(it2) << endl;
            list1.emplace(it1, *(it2));
            it2++;
            list2.pop_front();
        }
        print_list(list1);
        print_list(list2);

        if (it1 != end(list1))  cout << "it1 is pointing at " << *(it1) << endl;
        if (it2 != end(list2))  cout << "it2 is pointing at " << *(it2) << endl;

        cout << endl;
    }
    cout << "alternative insert: " << endl; print_list(list1);
}


int compare(list<char>& list1, list<char>& list2)
{
    // Traverse both lists.
    // Stop when either end of a linked list is reached or current characters don't match
    auto it1 = begin(list1);
    auto it2 = begin(list2);

    while (it1 != end(list1) && it2 != end(list2) && *it1 == *it2) {
        it1++;
        it2++;
    }

    //  If both lists are not empty, compare mismatching characters
    if (it1 != end(list1) && it2 != end(list2))
        return (*it1 > *it2)? 1: -1;

    // If either of the two lists has reached end
    if (it1 != end(list1) && it2 == end(list2)) return 1;
    if (it2 != end(list2) && it1 == end(list1)) return -1;

    // If none of the above conditions is true, both lists have reached end
    return 0;
}

void union_of_lists(list<int>& list1, list<int>& list2, list<int>& listsUnion){
    auto it1 = begin(list1);
    auto it2 = begin(list2);
    while (it1 != end(list1) && it2 != end(list2)) {
        if (*it1 <= *it2) {
                listsUnion.emplace_back(*it1);
                if (*it1 == *it2)
                    it2++;
                it1++;
            }
            else if (*it1 > *it2){
                listsUnion.emplace_back(*it2);
                it2++;
            }
            //print_list(listsUnion); cout << endl;
    }
    while (it1 != end(list1)){
        listsUnion.emplace_back(*it1);
        it1++;
    }
    while (it2 != end(list2)){
        listsUnion.emplace_back(*it2);
        it2++;
    }
}

void intersection_of_lists(list<int>& list1, list<int>& list2, list<int>& listsIntersection){
    auto it1 = begin(list1);
    auto it2 = begin(list2);
    // Itersection O(n + m)
    while (it1 != end(list1) && it2 != end(list2)){
        if (*it1 < *it2)        it1++;
        else if (*it1 > *it2)   it2++;
        else {
            listsIntersection.emplace_back(*it1);
            it1++;
            it2++;
            //print_list(listsIntersection); cout << endl;
        }
    }
}


void union_of_lists_with_hashing(list<int>& list1, list<int>& list2, list<int>& listsUnion){
    map<int, int> elems;
    auto i = 0;
    for( auto it = begin(list1); it != end(list1); it++) {
        if (elems.find(*it) == end(elems)) {
            elems.insert(make_pair(*it, i));
            listsUnion.emplace_back(*it);
            i++;
        }
    }
    for( auto it = begin(list2); it != end(list2); it++) {
        if (elems.find(*it) == end(elems)) {
            elems.insert(make_pair(*it, i));
            listsUnion.emplace_back(*it);
            i++;
        }
    }
}
void intersection_of_lists_with_hashing(list<int>& list1, list<int>& list2, list<int>& listsIntersect){
    map<int, int> elems;
    auto i = 0;
    for( auto it = begin(list1); it != end(list1); it++) {
        if (elems.find(*it) == end(elems)) {
            elems.insert(make_pair(*it, i));
            i++;
        }
    }
    for( auto it = begin(list2); it != end(list2); it++) {
        if (elems.find(*it) != end(elems)) {
            listsIntersect.emplace_back(*it);
        }
    }
}

