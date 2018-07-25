//
// Created by Svetlana Matculevich on 26/06/2017.
//

#ifndef DEMOS_HOLDER_H
#define DEMOS_HOLDER_H

#include <string>

class Resource;


class Holder {

private:
    std::string name;
    int number;
public:
    static const int Limit = 7;
    Holder(std::string s="", int n=0) : name(s), number(n){} // default parameters
    void Increase (int num=1); // default parameters
    int SomeFunc(int n) const {return n;}
    int GetNumber(){return number;}
    // sign 'hey, you are taking the resource pointer and you are not doing anythng with it'

    #pragma warning(push)               // taking all the states and push it to the stack
    #pragma warning(disable : 40100)    // disable certain warning
    int SomeFunc(Resource* r) const {return -99;}
    #pragma warning(pop)
    // direction to the compiler

};


#endif //DEMOS_HOLDER_H
