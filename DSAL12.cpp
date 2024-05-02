/*
12.Department maintains a student information. The file contains roll number, name, division and
address. Allow user to add, delete information of student. Display information of particular
employee. If record of student does not exist an appropriate message is displayed. If it is, then the
system displays the student details. Use sequential file to main the data.
*/
#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class student {
public:
    int rollno;
    char name[50];
    char add[50];
    char div[5];

    void setData() {
        cout << "Enter Roll no: ";
        cin >> rollno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Address of student: ";
        cin >> add;
        cout << "Division of student: ";
        cin >> div;
    }

    void showData() {
        cout << "\n Roll no. of student: " << rollno;
        cout << "\n Name of the student: " << name;
        cout << "\n Address of student: " << add;
        cout << "\n Division of student: " << div;
    }

    int retrollno() {
        return rollno;
    }
};

void write_record() {
    ofstream outfile;
    outfile.open("StudentData", ios::binary | ios::app);
    student obj;
    obj.setData();
    outfile.write((char*)&obj, sizeof(obj));
    outfile.close();
}

void display_record() {
    ifstream infile;
    infile.open("StudentData", ios::binary);
    student obj;
    while (infile.read((char*)&obj, sizeof(obj))) {
        obj.showData();
    }
    infile.close();
}

void search_record(int n) {
    bool flag = false;
    ifstream infile;
    infile.open("StudentData", ios::binary);
    student obj;
    while (infile.read((char*)&obj, sizeof(obj))) {
        if (obj.rollno == n) {
            flag = true;
            obj.showData();
            break;
        }
    }
    infile.close();
    if (!flag) {
        cout << "Record for roll no. " << n << " is not found in the file.";
    }
}

void delete_record(int n) {
    student obj;
    ifstream infile;
    infile.open("StudentData", ios::binary);
    ofstream outfile;
    outfile.open("StudentNewData", ios::out | ios::binary);
    while (infile.read((char*)&obj, sizeof(obj))) {
        if (obj.retrollno() != n) {
            outfile.write((char*)&obj, sizeof(obj));
        }
    }
    infile.close();
    outfile.close();
    remove("StudentData");
    rename("StudentNewData", "StudentData");
}

int main() {
    int ch;
    do {
        cout << "\n******File Operations******\n";
        cout << " 1. Add Record.\n";
        cout << " 2. Display Record.\n";
        cout << " 3. Search a particular Record.\n";
        cout << " 4. Delete particular Record.\n";
        cout << " 5. Exit.\n";
        cout << " Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter total no. of records you want to store in a file: ";
                int n;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    write_record();
                }
                break;
            case 2:
                cout << "\nList of records: ";
                display_record();
                break;
            case 3:
                cout << "Enter student roll no. whose record you want to search: ";
                int s;
                cin >> s;
                search_record(s);
                break;
            case 4:
                cout << "Enter student roll no. whose record you want to delete: ";
                int t;
                cin >> t;
                delete_record(t);
                cout << "Record Deleted Successfully!!";
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!";
        }
    } while (ch != 5);
    return 0;
}

