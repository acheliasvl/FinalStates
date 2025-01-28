#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream> 

class Person {
protected:
    int id;
    std::string name;

public:
    Person(int id, const std::string& name);
    virtual ~Person();
    virtual void display() const = 0; 
    int getId() const;
    std::string getName() const;
};

#endif
