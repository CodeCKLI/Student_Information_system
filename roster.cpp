#include "roster.h"
void Roster::parse(string studentdata)
{
    int rhs = studentdata.find(',');
    string sID = studentdata.substr(0, rhs);
    int lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    string sFName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentdata.find(',', lhs);
    string sLName = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1; 
    rhs = studentdata.find(",", lhs);
    string sEmail = studentdata.substr(lhs, rhs - lhs);
    lhs = rhs + 1; 
    rhs = studentdata.find(",", lhs);
    int sAge = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1; 
    rhs = studentdata.find(",", lhs);
    int d1 = stod(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1; 
    rhs = studentdata.find(",", lhs);
    int d2 = stod(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1; 
    rhs = studentdata.find(",", lhs);
    int d3 = stod(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    DegreeProgram dt = SECURITY;
    if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') dt = SECURITY;
    else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') dt = SOFTWARE;
    else if (studentdata.at(lhs) == 'N') dt = NETWORK;
    add(sID, sFName, sLName, sEmail, sAge, d1, d2, d3, dt);
}
void Roster::add(string studentID, string fName, string lName, string email, int age, int d1, int d2, int d3, DegreeProgram dt)
{
    int darr[3] = { d1, d2, d3 };
    classRosterArray[++lastIndex] = new Student(studentID, fName, lName, email, age, darr, dt);
}
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            any = true;
            cout << email << ":" << classRosterArray[i]->getFname() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0] +
                classRosterArray[i]->getDays()[1] +
                classRosterArray[i]->getDays()[2]) / 3 << std::endl;
        }
    }
}
void Roster::printByDegreeProgram(DegreeProgram dt)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dt) classRosterArray[i]->print();
    }
    cout << std::endl;
}
void Roster::remove(string studentID)
{
    bool found = false; 
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            found = true;
            if (i < studentDataTable - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
                classRosterArray[studentDataTable - 1] = temp;
                temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 2];
                classRosterArray[studentDataTable - 2] = temp;
            }
            Roster::lastIndex--;

        }
    }
    if (found)
    {
        cout << studentID << " was being removed from the roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " was not found." << std::endl << std::endl;; 
}
Roster::~Roster()
{
    cout << "Destructor is called" << std::endl << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        cout << "Removing student " << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}