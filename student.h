#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
	public:
		const static int daysInCourseArray = 3;
	private:
        string studentID;
        string fname;
        string lname;
        string email;
        int age;
        int days[daysInCourseArray];
        DegreeProgram degreeProgram;
    public:
        Student();
        Student(string studentID, string fname, string lname, string email, int age, int days[], DegreeProgram degreeProgram);
        ~Student();

        //Getters
        string getID();
        string getFname();
        string getLname();
        string getEmail();
        int getAge();
        int* getDays();
        DegreeProgram getDegreeProgram();

        //Setters
        void setID(string studentID);
        void setFname(string fname);
        void setLname(string lname);
        void setEmail(string email);
        void setAge(int age);
        void setDays(int days[]);
        void setDegreeProgram(DegreeProgram dt);
        static void printHeader();
        void print();


};