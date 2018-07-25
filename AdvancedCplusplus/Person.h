#ifndef DEMOS_PERSON_H  // if Person.h not defined
#define DEMOS_PERSON_H  // the defined Person.h

#include <string>
#include <iostream>
#include <memory>
#include "Resource.h"
//#include "Address.h"

class Person {

    // by default everything is private

private:

    std::string firstname;
    std::string lastname;
    int arbitrarynumber;    // age, salary, ...

    // if we don't want our Person be allowed to copy
    // we define copy contructor and copy assigment as private members
    // Person(const Person&);
    // Person& operator=(const Person&);
    // this way compiler will tell us

    // 0st way of storing it is just
    // ------------------------------------------------------------------------------------
    // Resource pResource;

    // Ist way of handing resources: raw pointer
    // ------------------------------------------------------------------------------------
    // Resource* pResource;

    // IInd way of handling resources: shared pointer
    // ------------------------------------------------------------------------------------
    std::shared_ptr<Resource> pResource;
    // - for the shared_ptr pointer, one doesn't need the copy constructor any more
    //   and copy assigneng since the resource is simply shared
    // - we don't need to initialize it, it initialized itself
    // - we also don't need to care about it when is getting destructed
    // - while adding the resources, we need to check, if there was already one
    // -

    // IIIrd way of handling resources: unique pointer
    // ------------------------------------------------------------------------------------
    // std::unique_ptr<Resource> pResource;
    // this eleminates any need in the copy constructor and assignment
    // if we have unique pointer => we can always get raw pointer by .get()

    // std::shared_ptr< Accum<std::string> > pResource;
    // the copy constructor is not needed any more
    // operator equals is not needed any more
    // shared_ptr initialize themselve by null
    // no need to have a destructor

    // we CANNOT initialize the static members!
    static int lifeExpectancy; // this will be initialized by 0

protected:
    //accessible within a class and by the inheritents of the class
    int ssn;

public:

    // const are not static, so we have to explicitely specify this
    const static int female = 0;
    const static int male = 1;

    int age;
    std::string name;
    int sex;
    //Address* address;

    // IMPORTANT:
    // when we are not having the default constructor
    // compiler makes the default constructor for us
    // as soon as we define some constructor it is a default one
    Person(std::string _firstname = "", std::string _lastname = "", int _arbitrarynumber = 0);    // prototype of the constuructor
    // the compiler does nothing himself
    // so we have to defined constructor that doesn't take any initialing values
    Person();   // default constructor
    virtual ~Person();  //  default destructor
    // it is safer to have the destructor virtual because
    // if some inherited from it object has a handle that must be deleted
    // the destructor for Tweeter MUST be called with the destructor for a Person

    Person(const Person&);              // copy contructor
    Person&  operator=(const Person&);  // copy assignment operator

    Person(Person&&);              // move contructor
    //Person&  operator=(Person&&);  // move assignment operator

    //Person(int age, std::string name, int sex);
    //Person(int age, std::string name, int sex, int house_number, std::string street_name, std::string city);


    // inline functions Set and Get
    int GetNumber() const {return arbitrarynumber;}
    void SetNumber(int number){ arbitrarynumber=number;}

    virtual std::string GetName() const {return firstname + " " + lastname;}
    void SetName(std::string _firstname, std::string _lastname){ firstname = _firstname; lastname = _lastname; }
    void SetFirstName(std::string _firstname){ firstname = _firstname; }
    void SetLastName(std::string _lastname){ lastname = _lastname; }

    //void SetResource(std::string resourcename);
    //std::string GetResourceName() const {return pResource->GetName();}

    bool operator<(const Person&) const;
    bool operator>(const Person&) const;
    bool operator<(int) const;
    friend bool operator<(int, const Person&);
    // some of the operation overloads must be friend functions
    // it gives the prevelage to this function to access objects data_members


    void AddResourse(std::string resourceName);
    std::string GetResourceName() const {return pResource->GetName();}
    // it make this function a privileges to access the private friends

    virtual void greet() const ;
    static int getLifeExpentancy() { return lifeExpectancy; }

};

bool operator<(int, Person&);
#endif //DEMOS_PERSON_H
