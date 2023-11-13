#include "student.h"
Student::Student()
{
    this->studentID = "";
    this->fname = "";
    this->lname = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArray; i++) this->days[i] = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;
}
Student::Student(string studentID, string fname, string lname, string email, int age, int days[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->fname = fname;
    this->lname = lname;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysInCourseArray; i++) this->days[i] = days[i];
    this->degreeProgram = degreeProgram;
}
Student::~Student() {}
//Getters
string Student::getID() { return this->studentID; }
string Student::getFname() { return this->fname; }
string Student::getLname() { return this->lname; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }
//Setters
void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFname(string fname) { this->fname = fname; }
void Student::setLname(string lname) { this->lname = lname; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
{
    for (int i = 0; i < daysInCourseArray; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dt) { this->degreeProgram = dt; }

void Student::print()
{
    cout << this->getID() << '\t';
    cout << this->getFname() << '\t';
    cout << this->getLname() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}

void Student::printHeader()
{
    cout << "ID" << '\t' << "First" << '\t' << "Last" << '\t' << "Email Address" << '\t' << "Age" << '\t' << "Days to Complete" << '\t' << "Degree" << std::endl;
}
