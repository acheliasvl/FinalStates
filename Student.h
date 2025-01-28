#include <string>
#include <iostream>
#include "Person.h"
#ifndef STUDENT_H
#define STUDENT_H

class Student : public Person {
private:
  int id; 
  string name;
  string course;
  double grade;

public:
  Student(int id, const std::string& name, const std::string& course, double grade);
  void display() const override;
  void setName(string n); 
  void setID(int i); 
  void setCourse(string c); 
  void setGrade(double grade);
  string getCourse() const;
  double getGrade() const; 
};

#endif
