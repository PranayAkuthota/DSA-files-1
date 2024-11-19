#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks;
public:
    void input() {
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Roll Number: "; cin >> rollNo;
        cout << "Enter Marks: "; cin >> marks;
    }

    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Marks: " << marks << endl;
    }

    void saveToFile() {
        ofstream outFile("student_records.txt", ios::app);
        outFile << name << " " << rollNo << " " << marks << endl;
        outFile.close();
    }

    void readFromFile() {
        ifstream inFile("student_records.txt");
        if (!inFile) {
            cout << "No file found!" << endl;
            return; 
        }
        while (inFile >> name >> rollNo >> marks) {
            display();
        }
        inFile.close();
    }
};

int main() {
    Student student;
    int choice;
    
    while (true) {
        cout << "\n1. Add Student Record\n2. View All Records\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            student.input();
            student.saveToFile();
            break;
        case 2:
            student.readFromFile();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
