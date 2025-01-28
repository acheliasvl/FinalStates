#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "Person.h"

Person :: Person (int ident, const std:: string& n){
  id = ident; 
  name = n; 
}

Person :: ~Person (){}

int Person::getId() const { 
    return id; 
}

string Person::getName() const { 
    return name; 
}

#include "Student.h"

Student::Student(int id, const string& name, const string& course, double grade)
  : Person(id, name), course(course), grade(grade) {}

void Student::display() const {
  cout << "ID: " << id << ", Name: " << name << ", Course: " << course << ", Grade: " << grade << std::endl;
}

void Student :: setName(string n){
  name = n; 
}

void Student :: setID(int i){
  id = i; 
}

void Student :: setCourse(string c){
  course = c; 
}
void Student::setGrade(double grade) {
  this->grade = grade;
}

string Student :: getCourse() const{
  return course;
} 

double Student :: getGrade() const{
  return grade; 
}

#include "Admin.h"

void Admin::addStudent(int id, const string& name, const string& course, double grade) {
  students.emplace_back(id, name, course, grade);
}

void Admin::viewStudents() const {
  if (students.empty()) {
      cout << "No students found in the list." << endl;
      return;
  }
  for (const auto& student : students)
    student.display();
}

void Admin::removeStudents(int id){

  for(vector<Student>::iterator it = students.begin() ; it != students.end() ; it++){
    if(it->getId() == id){
      students.erase(it);
      return ; 
    }
    else 
      cout<< "Student with id not found " << endl; 
      
  }
}

void Admin::updateStudents(int id, const string& name, const string& course, double grade) {
    for (auto& student : students) { 
        if (student.getId() == id) {
            if (!name.empty()) {
                student.setName(name);
            }

            if (!course.empty()) {
                student.setCourse(course);
            }

            if (grade >= 0) {
                student.setGrade(grade);
            }

            cout << "Student with ID " << id << " updated successfully.\n";
            return;
        }
    }

  cout << "Error: Student with ID " << id << " not found.\n";
}



void Admin::saveToFile(const string& filename) const {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    for (const auto& student : students) {
        outFile << student.getId() << ","
                << student.getName() << ","
                << student.getCourse() << ","
                << student.getGrade() << endl;
    }
}


void Admin::loadFromFile(const string& filename) {

  try {

    ifstream inFile(filename);
    if (!inFile) {
      throw runtime_error("File not found.");
    }
  
    students.empty(); 

    int id;
    string name, course;
    double grade;

    while (inFile >> id) {
    inFile.ignore();                
    getline(inFile, name, ',');     
    getline(inFile, course, ',');  
    inFile >> grade;               
    inFile.ignore();               

    students.emplace_back(id, name, course, grade);
  }

  }
  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }


}


int main(){
  Admin admin;
  char choice;
  int id;
  string name, course;
  double grade;
  char loop;

  cout << "********** ~ Welcome to your Student Management System! ~ **********" << endl;  

  do{

  cout << "What modification do you want to do in your list? " << endl
  << "1. Adding new students" << endl << "2. Removing students" << endl << "3. Updating Student info" 
  << endl; 
  
  cin >> choice; 
  switch (choice)
  {
  case '1':{

    cout << endl; 
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Course: ";
    getline(cin, course);

    cout << "Enter Grade: ";
    cin >> grade;

    admin.addStudent(id, name, course, grade);
    admin.saveToFile("Location of your File coded hear");
    cout << "Student added successfully!" << endl;

    break;
  }
  
  case '2':{
    cout << endl; 
    cout << "Enter ID of student getting removed: ";
    cin >> id;
    admin.removeStudents(id);
    admin.saveToFile("Location of your File coded hear");

    cout << "Removed. (if id exists)" << endl; 
    break;
  }

  case '3':{
    cout << "\nEnter ID of the student to update: ";
    cin >> id;

    cout << "Enter new Name (or press Enter to keep current): ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter new Course (or press Enter to keep current): ";
    getline(cin, course);

    cout << "Enter new Grade (or -1 to keep current): ";
    cin >> grade;


    admin.updateStudents(id, name, course, grade);
    admin.saveToFile("Location of your File coded hear");
    admin.loadFromFile("Location of your File coded hear");

    break;
  }

  default:
    admin.viewStudents();
    break;
  }

  cout << "Do you want to continue with implementations? Y/N "; 
  cin >> loop; 
  
  cout << endl; 
  }while(loop == 'Y' || loop == 'y' ); 



  return 0;
}
