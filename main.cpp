#include "roster.h"
using namespace std;

int main()
{
    cout 
        << "-------------------------------------------------------\n"
        << "Course: C867 Scripting and Programming - Applications\n" 
        << "Programming Language: C++\n" 
        << "ID: 010875202\n" 
        << "Name: CHUN KAI LI\n" 
        << "-------------------------------------------------------\n"
        << std::endl << std::endl;
    const string studentData[] =
    {   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Chun Kai,Li,cli18@wgu.edu,30,04,09,13,SOFTWARE"
    };
    const int studentDataTable = 5;
    Roster classRoster;

    for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);

    cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    cout << std::endl;

    cout << "Displaying invalid email addess: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    cout << "Displaying average days per class:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << std::endl;

    cout << "Displaying all software students:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;


    cout << "Removed student: A3." << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    cout << "Removed student: A3." << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
 
}