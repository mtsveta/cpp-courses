//
// Created by Svetlana Matculevich on 25/06/2017.
//
#pragma once
#include <string>

#ifndef DEMOS_RESOURCE_H
#define DEMOS_RESOURCE_H


class Resource {

private:
    std::string name;
public:
    Resource(std::string n);

    Resource(const Resource& r); // copy contructor
    Resource(Resource&& r); // move contructor, we are stealing the guts of the resource, that's why we have to remove const (we should be able to change it, sort of)

    Resource& operator=(const Resource& r); // copy assigment
    Resource& operator=(Resource&& r);      // move assigment operator, resource should not be const

    ~Resource(void);    // destructor

    std::string GetName() const {return name;}

    bool operator>(const Resource& r) const {return name>r.GetName();}
    bool operator<(const Resource& r) const {return name<r.GetName();}
    bool operator==(const Resource& r) const {return name==r.GetName();}

};


#endif //DEMOS_RESOURCE_H
