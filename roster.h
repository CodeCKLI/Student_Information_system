#pragma once
#include "student.h"
class Roster
{
public:
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable];
    int lastIndex = -1;
public:
    void parse(string row);
    void add(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeprogram);
    void printAll();
    void printByDegreeProgram(DegreeProgram degreeprogram);
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentID);
    void remove(string studentID);
    ~Roster();
};