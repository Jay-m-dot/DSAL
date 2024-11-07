#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int roll_no;
    char name[30];
    char division[5];
    char address[50];

public:
    void accept();
    void display() const; // Mark display as const since it doesn't modify the object
    int getRollNo() const {
        return roll_no;
    }
};

void Student::accept() {
    cout << "\nEnter Roll Number: ";
    cin >> roll_no;
    cout << "Enter Name: ";
    cin.ignore(); // Clear the newline character from input buffer
    cin.getline(name, 30);
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Address: ";
    cin.ignore();
    cin.getline(address, 50);
    cout << "\n";
}

void Student::display() const {
    cout << "\n    " << roll_no << "\t  " << name << "\t\t " << division << "\t      " << address;
}

void create() {
    Student s;
    int n;
    ofstream out("Student.txt", ios::binary); // Open in binary mode
    cout << "\nHow many records do you want to enter?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        s.accept();
        out.write(reinterpret_cast<char*>(&s), sizeof(s));
    }
    out.close();
}

void search() {
    int roll_no;
    cout << "\nEnter Roll Number To Be Searched: ";
    cin >> roll_no;
    ifstream infile("Student.txt", ios::binary); // Open in binary mode
    Student s;
    bool found = false;

    while (infile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNo() == roll_no) {
            cout << "\nRecord Found\n";
            cout << "\nRoll Number          Name                      Division         Address";
            s.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord Not Found.";
    }
    infile.close();
}

void display() {
    Student s;
    ifstream infile("Student.txt", ios::binary); // Open in binary mode
    cout << "\nRoll Number          Name                      Division         Address";
    
    while (infile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.display();
    }
    infile.close();
}

void addRecord() {
    Student s;
    ofstream outfile("Student.txt", ios::binary | ios::app); // Open in binary mode and append
    s.accept();
    outfile.write(reinterpret_cast<char*>(&s), sizeof(s));
    outfile.close();
    cout << "Record Successfully Added.";
}

void deleteRecord() {
    int roll_no;
    cout << "\nEnter Roll Number Whose Record To Be Deleted: ";
    cin >> roll_no;
    
    ifstream infile("Student.txt", ios::binary); // to read from source file
    ofstream temp("temp.txt", ios::binary); // to write in destination file (temporary file)
    Student s;
    bool found = false;

    while (infile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNo() != roll_no) {
            temp.write(reinterpret_cast<char*>(&s), sizeof(s));
        } else {
            found = true;
            cout << "\nRecord Successfully Deleted.";
        }
    }

    if (!found) {
        cout << "\nRecord Not Found.";
    }

    infile.close();
    temp.close();
    remove("Student.txt");
    rename("temp.txt", "Student.txt");
}

int main() {
    int choice;
    ofstream out("Student.txt", ios::binary); // Ensure the file is created
    out.close();

    do {
        cout << "\nMenu:\n1) Create Database.\n2) Display.\n3) Add Record.\n4) Search Record.\n5) Delete Record.\n6) Exit.";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                addRecord();
                break;
            case 4:
                search();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                cout << "\nYou Have Successfully Exited...";
                break;
            default:
                cout << "\nINVALID CHOICE.";
        } 
    } while (choice != 6); // Change to exit on choice 6

    return 0;
}

