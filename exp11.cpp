#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void addStudent()
{
    ofstream file("db.txt", ios::app);
    string rn, name, div, add;
    cout << "\nenter roll no: ";
    cin >> rn;
    cout << "enter name: ";
    cin >> name;
    cout << "enter division: ";
    cin >> div;
    cout << "enter address: ";
    cin >> add;
    file << left << setw(20) << rn << setw(20) << name << setw(20) << div << setw(20) << add << endl;
    file.close();
    cout << "\nStudent added successfully!!" << endl;
}

void searchStudent()
{
    ifstream file("db.txt");
    string line, rn;
    cout << "\nenter roll no: ";
    cin >> rn;
    bool found = false;
    while (getline(file, line))
    {
        if (line.find(rn) != string::npos)
        {
            found = true;
            cout << "\nstudent record found" << endl;
            cout << line << endl;
        }
    }
    file.close();
    if (!found)
    {
        cout << "\nstudent does not exist!!" << endl;
    }
}

void deleteStudent()
{
    ifstream file("db.txt");
    string line, rn, fileData;
    cout << "\nenter roll no: ";
    cin >> rn;

    while (getline(file, line))
    {
        if (line.find(rn) == string::npos)
        {
            fileData += line;
            fileData += "\n";
        }
    }
    file.close();

    cout << "\nstudent deleted successfully!!" << endl;

    ofstream f1("db.txt", ios::out);
    f1 << fileData;
    f1.close();
}

void displayStudent()
{
    ifstream file("db.txt");
    string line;
    cout << "\nPrinting Student Data:" << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
int main()
{
    ofstream file("db.txt", ios::out);
    file << left << setw(20) << "Roll Number" << setw(20) << "Name" << setw(20) << "Division" << setw(20) << "Address" << endl;
    int ch;
    while (ch != -1)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display Student Data" << endl;
        cout << "5. Exit" << endl;
        cout << "enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            addStudent();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            displayStudent();
            break;
        case 5:
            cout << "\nexiting the program!!" << endl;
            break;
        }
    }
}