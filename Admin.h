#include <vector>
#include <string>
#include <iostream>
#include "Student.h"

#ifndef ADMIN_H
#define ADMIN_H

class Admin {
private:
  vector<Student> students;

public:
  void addStudent(int id, const string& name, const string& course, double grade);
  void viewStudents() const;
  void removeStudents(int id);
  void updateStudents(int id, const string& name, const string& course, double grade); 
  void saveToFile(const string& filename) const;
  void loadFromFile(const std::string& filename);
};

#endif
