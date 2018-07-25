//
// Created by Svetlana Matculevich on 24/06/2017.
//
#include "Person.h"
//#include "Noise.h"
#include <string>
//#include "Accum.h"
// we use initialize syntax
// it helps in the case when the initialization would be expensive
// we are not setting the default value and then

using namespace std;

// we can initialize it here
int Person::lifeExpectancy = 40;

Person::Person() : firstname(""), lastname(""), arbitrarynumber(0) {
    cout << "constructing an empty person " << endl; };

Person::Person(string _firstname, string _lastname, int _arbitrarynumber) :
        firstname(_firstname), lastname(_lastname), arbitrarynumber(_arbitrarynumber){

    std::cout << "constructing a person " << GetName() << std::endl;

}

// copy constuctor
Person::Person(const Person& p) :
        firstname(p.firstname), lastname(p.lastname), arbitrarynumber(p.arbitrarynumber){

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "copy constructing a person " << GetName() << std::endl;
    // I method with raw pointers:
    // if the would be resource
    //if (p.pResource)
    //    pResource = new Resource(p.pResource->GetName());

    // IIIrd method with unique pointer
    // --------------------------------------------------
    //pResource.reset(new Resource(p.pResource->GetName()));

    // IInd method with shared pointer
    // --------------------------------------------------
    pResource.reset();
    pResource = make_shared<Resource>(Resource(p.pResource->GetName()));
    // pResource(new Resource(p.pResource->GetName()));
    // pResource.reset(new Resource(p.GetResourceName()));
    // auto* a = p.address;
    // address = new Address(a->house_number, a->street, a->city);

    std::cout << "-----------------------------------------------------" << std::endl;

}


// move constuctor
Person::Person(Person&& p) :
        firstname(p.firstname), lastname(p.lastname), arbitrarynumber(p.arbitrarynumber){

    //if the would be resourse
    //pResource.reset(new Resource(p.GetResourceName()));
    //auto* a = p.address;
    //address = new Address(a->house_number, a->street, a->city);

    std::cout << "move constructing a person "
              << GetName() << std::endl;


}

void Person::AddResourse(std::string resourceName) {
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "adding the resource " << GetName() << std::endl;

    // 0st methods with just member object:
    // Resource newOne(resourceName);
    // pResource = newOne;

    // Ist method with raw pointers:
    // if we are creating the resource with a word new:
    // we are doing it on the heap (free storage)
    // if are doing it like that ?
    //delete pResource;
    //pResource = new Resource("Resource for " + this->GetName());

    // IInd method with shared pointers:
    // pResource.reset();
    pResource = std::make_shared<Resource>(resourceName);

    //Resource r("Resource for " + this->GetName());
    //pResource = &r;

    // IIIrd methods unique pointers:
    //pResource.reset(new Resource(resourceName));

    std::cout << "-----------------------------------------------------" << std::endl;
}

// assingment copy operator overload
Person& Person::operator=(const Person& p ){

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "assigning a person " << GetName() << " to another one" << std::endl;

    firstname = p.firstname;
    lastname = p.lastname;
    arbitrarynumber = p.arbitrarynumber;

    //Ist way to work with raw pointers:
    // --------------------------------------------------
    //delete pResource;
    //pResource = new Resource(p.pResource->GetName());

    // IInd method with shared pointer
    // --------------------------------------------------
    pResource.reset();
    pResource = p.pResource;

    // IIIrd method with unique pointer
    // --------------------------------------------------
    // unique pointer will clear himself by assigning a new
    // first it will create new one
    // then he will delete the old one
    //pResource.reset(new Resource(p.pResource->GetName()));

    std::cout << "-----------------------------------------------------" << std::endl;
    return *this;
}

Person::~Person(){
    //if (address != nullptr) {
    //    delete address;
    //    address = nullptr;
    //}

    // this is only required when working with raw pointers
    // delete pResource; // corresponding to the new Resource

    std::cout << "destructing a person " << GetName() << std::endl;
}

// comparing the Person to another person
bool Person::operator<(const Person &p) const {
    return arbitrarynumber <= p.arbitrarynumber;
}
bool Person::operator>(const Person &p) const {
    return !(Person::operator<(p));
}
bool Person::operator<(int i) const {
    return arbitrarynumber < i;
}
bool operator<(int i, const Person& p){
    //return i < p.arbitrarynumber; // if operator< is the friend functions
    return i < p.GetNumber(); // if operator< i the free function
}

//void Person::SetResource(std::string resourcename) {
    //Resource newResource(resourcename);
    //pResource = newResource;
    // pResource.reset(new Resource(resourcename)); // for the unique_ptr
    //pResource = make_shared<Resource>(resourcename);
//}


void Person::greet() const {
    cout << "Hello! My name is " << name << " and I am " << age << " years old." << endl;
    //if (address)    cout << "I live in " << address->city << "." << endl;
}
/*
Person::Person(int _age, std::string _name, int _sex) :
        age(_age), name(_name), sex(_sex) {
    //address = nullptr;
}

Person::Person(int _age, std::string _name, int _sex, int _house_number, std::string _street_name, std::string _city) :
        Person(_age, _name, _sex)
{
    // when
    //if (address != nullptr) delete address;

    //address = new Address(_house_number, _street_name, _city);
}

*/