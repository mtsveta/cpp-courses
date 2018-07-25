//
// Created by Svetlana Matculevich on 25/06/2017.
//

#include "Resource.h"
#include <iostream>

using namespace std;

Resource::Resource(std::string n) : name(n) {
    cout << "constructing a resource for " << n << endl;
}
//
Resource::Resource(const Resource &r) : name(r.name) {
    cout << "copy constructing of a resource for " << name << endl;
}

Resource::Resource(Resource && r) : name(std::move(r.name)) { // it will leave the r with no name
    cout << "move constructing of a resource for " << name << endl;
}

//this copy assignment is only required for the handing the raw pointers
Resource& Resource::operator=(const Resource &r) {
    cout << "copy assigning a resource for " << name << endl;
    name = r.GetName();
    return *this;
}

Resource& Resource::operator=(Resource && r) {
    cout << "move assigning a resource for " << name << endl;
    // if class contained true Resource,
    // - check for self assignment then
    // - clean up existing resource before setting new values
    if (this != & r) { // checking for the self-assignment
        name = std::move(r.name); //
        r.name.clear();
    }
    return *this;
}
Resource::~Resource() {
    cout << "destructing a resource for " << name << endl;
}