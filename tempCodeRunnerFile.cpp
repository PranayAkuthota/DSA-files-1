#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <ctime>
#include <stdexcept>
#include <limits> 
#include <iomanip> 


using namespace std;

//Function to get current date & time
string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string dateTime(dt);
    dateTime.pop_back(); 
    return dateTime;
}

// Class for Complaints
class ComplaintSystem {
private:
    vector<string> complaints;

public:
    void lodgeComplaint(const string &complaint) {
        string entry = getCurrentTime() + " - " + complaint;
        complaints.push_back(entry);
        saveToFile(entry);
    }

    void saveToFile(const string &complaint) {
        ofstream file("complaints.txt", ios::app);
        if (!file) {
            cerr << "ERROR! Unable to open complaint file. Attempting to create a new file." << endl;
            file.open("complaints.txt");
            if (!file) {
                cerr << "ERROR! Unable to create complaint file. Check your permissions and directory." << endl;
                throw runtime_error("Unable to create complaint file.");
            }
        }
        file << complaint << endl;
        file.close();
    }

    void viewComplaints() {
        ifstream file("complaints.txt");
        if (!file) {
            cout << "No complaints found.\n";
            return;
        }
        string line;
        cout << "\nComplaints:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

// Class for IT Department to handle requests
class ITDepartment {
private:
    vector<string> requests;

public:
    void lodgeRequest(const string &request) {
        string entry = getCurrentTime() + " - " + request;
        requests.push_back(entry);
        saveToFile(entry);
    }

    void saveToFile(const string &request) {
        ofstream file("it_requests.txt", ios::app);
        if (!file) {
            cerr << "ERROR! Unable to open IT request file. Attempting to create a new file." << endl;
            file.open("it_requests.txt");
            if (!file) {
                cerr << "ERROR! Unable to create IT request file. Check your permissions and directory." << endl;
                throw runtime_error("Unable to create IT request file.");
            }
        }
        file << request << endl;
        file.close();
    }

    void viewRequests() {
        ifstream file("it_requests.txt");
        if (!file) {
            cout << "No IT requests found.\n";
            return;
        }
        string line;
        cout << "\nIT Requests:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

// Class Room management
class Room {
private:
    int roomNumber;
    bool isOccupied;
    string studentName;

public:
    Room(int num) : roomNumber(num), isOccupied(false) {}

    void assignRoom(const string &name) {
        if (isOccupied) {
            cout << "Room " << roomNumber << " is already occupied.\n";
        } else {
            studentName = name;
            isOccupied = true;
            cout << "Room " << roomNumber << " assigned to " << studentName << ".\n";
        }
    }

    void vacateRoom() {
        if (isOccupied) {
            cout << "Room " << roomNumber << " vacated by " << studentName << ".\n";
            studentName = "";
            isOccupied = false;
        } else {
            cout << "Room " << roomNumber << " is already vacant.\n";
        }
    }

    void displayStatus() {
        cout << "Room " << roomNumber << " - " 
             << (isOccupied ? "Occupied" : "Vacant") << endl;
    }
};

// Class for Mess details
class Mess {
public:
    void displayTiming() {
        cout << "\n--- Mess Timing ---\n";
        cout << "Breakfast: 7:30 AM - 9:30 AM\n";
        cout << "Lunch: 12:00 PM - 2:00 PM\n";
        cout << "Snacks: 5:30 PM - 6:30 PM\n";
        cout << "Dinner: 7:30 PM - 9:30 PM\n";
    }

    void displayMenu() {
    // Table header
        cout << left << setw(15) << "Day" 
             << setw(20) << "Breakfast" 
             << setw(20) << "Lunch" 
             << setw(20) << "Dinner" 
             << endl;
    
        cout << setfill('-') << setw(75) << "" << setfill(' ') << endl; // Line under header
    
        // MENU TIMETABLE
        cout << left << setw(15) << "Monday" 
             << setw(20) << "Dosa" 
             << setw(20) << "Rice, Dal, Aalo" 
             << setw(20) << "Curry, Rice" 
             << endl;
    
        cout << left << setw(15) << "Tuesday" 
             << setw(20) << "Omelette" 
             << setw(20) << "Pasta, Salad" 
             << setw(20) << "Paneer, Chapati" 
             << endl;
    
        cout << left << setw(15) << "Wednesday" 
             << setw(20) << "Idli, Sambhar" 
             << setw(20) << "Khichdi" 
             << setw(20) << "Vegetable Biryani" 
             << endl;
    
        cout << left << setw(15) << "Thursday" 
             << setw(20) << "Chai Toast" 
             << setw(20) << "Chole Bhature" 
             << setw(20) << "Pasta, Garlic Bread" 
             << endl;
    
        cout << left << setw(15) << "Friday" 
             << setw(20) << "Poha" 
             << setw(20) << "Rice, Rajma" 
             << setw(20) << "Biryani, Raita" 
             << endl;
    
        cout << left << setw(15) << "Saturday" 
             << setw(20) << "Upma" 
             << setw(20) << "Aloo Paratha" 
             << setw(20) << "Mixed Veg, Chapati" 
             << endl;
    
        cout << left << setw(15) << "Sunday" 
             << setw(20) << "Banana, Chocos" 
             << setw(20) << "Vegetable Pulao" 
             << setw(20) << "Special Thali" 
             << endl;
    }
};

// Class for managing sports facilities
class Sports {
private:
    unordered_map<string, int> availableEquipment; // Track available equipment
    unordered_map<string, string> issuedEquipment; // Track issued equipment

public:
    Sports() {
        // Initialize available equipment
        availableEquipment["Badminton Rackets"] = 10;
        availableEquipment["Cricket Bats"] = 5;
        availableEquipment["Table Tennis Bats"] = 8;
        availableEquipment["Fitness Equipment (Dumbbells)"] = 15;
        availableEquipment["Yoga Mats"] = 10;
    }

    void displayFacilities() {
        cout << "\n--- Sports Facilities ---\n";
        cout << "1. Gym\n";
        cout << "2. Badminton Court\n";
        cout << "3. Cricket Ground\n";
        cout << "4. Table Tennis\n";
    }

    void displayTimings() {
        cout << "\n--- Sports Timings ---\n";
        cout << "Gym: 24x7\n";
        cout << "Badminton Court: 4:00 PM - 8:00 PM\n";
        cout << "Cricket Ground: 5:00 PM - 9:00 PM\n";
        cout << "Table Tennis: 3:00 PM - 7:00 PM\n";
    }

    void displayEquipment() {
        cout << "\n--- Available Equipment to Borrow ---\n";
        int index = 1;
        for (const auto &item : availableEquipment) {
            cout << index++ << ". " << item.first << ": " << item.second << " available\n";
        }
    }

    void issueEquipment(int equipmentIndex, const string &studentName) {
        if (equipmentIndex < 1 || equipmentIndex > availableEquipment.size()) {
            cout << "Invalid choice. Please select a valid equipment number.\n";
            return;
        }

        auto it = availableEquipment.begin();
        advance(it, equipmentIndex - 1); // Move iterator to the selected index
        string equipmentName = it->first;

        // Check if equipment is available
        if (it->second > 0) {
            it->second--; // Decrease the available count
            issuedEquipment[equipmentName] = studentName; // Track issued equipment
            cout << equipmentName << " has been issued to " << studentName << ".\n";
        } else {
            cout << "Sorry, " << equipmentName << " is not available.\n";
        }
    }

    void returnEquipment(const string &studentName) {
        cout << "\n--- Issued Equipment ---\n";
        int index = 1;
        vector<string> issuedItems;

        // List issued equipment
        for (const auto &item : issuedEquipment) {
            if (item.second == studentName) {
                cout << index++ << ". " << item.first << endl;
                issuedItems.push_back(item.first); // Keep track of the items
            }
        }

        if (issuedItems.empty()) {
            cout << "No equipment issued to you.\n";
            return;
        }

        int equipmentIndex;
        cout << "Select the number of the equipment you want to return: ";
        cin >> equipmentIndex;

        if (equipmentIndex < 1 || equipmentIndex > issuedItems.size()) {
            cout << "Invalid choice. Please select a valid equipment number.\n";
            return;
        }

        string equipmentName = issuedItems[equipmentIndex - 1]; // Get the selected equipment

        // Check if the equipment was issued to the student
        if (issuedEquipment.find(equipmentName) != issuedEquipment.end() &&
            issuedEquipment[equipmentName] == studentName) {
            availableEquipment[equipmentName]++; // Increase the available count
            issuedEquipment.erase(equipmentName); // Remove from issued records
            cout << equipmentName << " has been returned by " << studentName << ".\n";
        } else {
            cout << "No record of " << equipmentName << " being issued to " << studentName << ".\n";
        }
    }
};

// Class for Management with access to all functionalities
class Management {
private:
    vector<shared_ptr<Room>> rooms;
    ITDepartment itDept;
    ComplaintSystem compSys;

public:
    Management() {
        for (int i = 101; i <= 105; ++i) {  // Example room range
            rooms.push_back(make_shared<Room>(i));
        }
    }

    void assignRoom(int roomNumber, const string &studentName) {
        if (roomNumber < 101 || roomNumber > 105) {
            throw out_of_range("Invalid room number.");
        }
        rooms[roomNumber - 101]->assignRoom(studentName);  // Adjusted indexing
    }

    void vacateRoom(int roomNumber) {
        if (roomNumber < 101 || roomNumber > 105) {
            throw out_of_range("Invalid room number.");
        }
        rooms[roomNumber - 101]->vacateRoom();  // Adjusted indexing
    }

    void viewAllRooms() {
        cout << "\nRoom Status:\n";
        for (const auto &room : rooms) {
            room->displayStatus();
        }
    }

    void viewComplaints() {
        compSys.viewComplaints();
    }

    void viewITRequests() {
        itDept.viewRequests();
    }

    ComplaintSystem& getComplaintSystem() { return compSys; }
    ITDepartment& getITDepartment() { return itDept; }

    // Method to display hostel details
    void viewHostelDetails() {
        cout << "\n--- Hostel Details ---\n";
        cout << "In-Out Timing: 6:00 AM to 10:00 PM\n\n";
        cout << "Shop Timing: 10:00 AM to 7.30 PM\n\n";
        cout << "Warden Name: Harsh Goud\n";
        cout << "Warden Contact Number: +91 1122334455\n";
        cout << "Warden Email: hwarden@iiitn.ac.in\n\n";
        cout << "Rules and Regulations:\n";
        cout << "1. Maintain silence after 10:00 PM.\n";
        cout << "2. Keep your rooms clean and tidy.\n";
        cout << "3. No outsiders are allowed after 10:00 PM.\n";
        cout << "4. Respect the hostel property.\n";
        cout << "5. Follow the mess timings strictly.\n";
    }
};

// Class for Student with limited access
class Student {
private:
    string name;

public:
    Student(const string &name) : name(name) {}

    void lodgeComplaint(ComplaintSystem &compSys) {
        int choice;
        string issue;
        do {
            cout << "\n--- Lodge a Complaint ---\n";
            cout << "1. Room not clean\n";
            cout << "2. AC not working\n";
            cout << "3. Wi-Fi issues\n";
            cout << "4. Other (Custom Complaint)\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            // Clear input buffer
            cin.clear();            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1:
                    compSys.lodgeComplaint(name + ": The room is not clean.");
                    cout << "Complaint lodged about room cleanliness.\n";
                    break;
                case 2:
                    compSys.lodgeComplaint(name + ": The AC is not working.");
                    cout << "Complaint lodged about AC issue.\n";
                    break;
                case 3:
                    compSys.lodgeComplaint(name + ": Wi-Fi issues.");
                    cout << "Complaint lodged about Wi-Fi issues.\n";
                    break;
                case 4:
                    cout << "Enter your complaint: ";
                    getline(cin, issue);
                    compSys.lodgeComplaint(name + ": " + issue);
                    cout << "Custom complaint lodged successfully.\n";
                    break;
                case 5:
                    cout << "Exiting Complaint Lodging.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5);
    }

    void requestITService(ITDepartment &itDept) {
        string request;
        cout << "Enter your IT request: ";
        getline(cin, request);
        itDept.lodgeRequest(name + ": " + request);
    }

    void viewHostelDetails(Management &mgmt) {
        mgmt.viewHostelDetails();
    }

    void viewMessDetails(Mess &mess) {
        int choice;
        do {
            cout << "\n--- Mess Details ---\n";
            cout << "1. Mess Timing\n";
            cout << "2. Mess Menu\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            // Clear input buffer
            cin.clear();            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1:
                    mess.displayTiming();
                    break;
                case 2:
                    mess.displayMenu();
                    break;
                case 3:
                    cout << "Exiting Mess Details.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 3);
    }

    void viewSportsDetails(Sports &sports) {
        int choice;
        do {
            cout << "\n--- Sports Details ---\n";
            cout << "1. View Facilities\n";
            cout << "2. View Timings\n";
            cout << "3. View Equipment\n";
            cout << "4. Issue Equipment\n"; // Option to issue equipment
            cout << "5. Return Equipment\n"; // Option to return equipment
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            // Clear input buffer
            cin.clear();            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1:
                    sports.displayFacilities();
                    break;
                case 2:
                    sports.displayTimings();
                    break;
                case 3:
                    sports.displayEquipment();
                    break;
                case 4: {
                    sports.displayEquipment(); // Show available equipment
                    int equipmentChoice;
                    cout << "Select the choice number of the equipment you want to issue: ";
                    cin >> equipmentChoice;
                    sports.issueEquipment(equipmentChoice, name); // Issue equipment
                    break;
                }
                case 5: {
                    sports.returnEquipment(name); // Return equipment
                    break;
                }
                case 6:
                    cout << "Exiting Sports Details.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 6);
    }
};

// Class for handling login credentials
class LoginSystem {
private:
    unordered_map<string, string> studentCredentials;
    unordered_map<string, string> managementCredentials;

public:
    LoginSystem() {
        // Student credentials
        studentCredentials["BT23CSE086"] = "PUKKU";
        studentCredentials["BT23CSE164"] = "Hariom";
        studentCredentials["BT23CSE157"] = "Ayush";
        studentCredentials["BT23CSE180"] = "Neehar";

        // Management credentials
        managementCredentials["admin"] = "admin123";
        managementCredentials["Vrinda"] = "OG_PROF";
    }

    bool studentLogin(string &studentName) {
        cout << "Enter student username: ";
        cin >> studentName;
        cout << "Enter password: ";
        string password;
        cin >> password;

        // Clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (studentCredentials.find(studentName) != studentCredentials.end() && 
            studentCredentials[studentName] == password) {
            cout << "Student login successful!\n";
            return true;
        }
        cout << "Invalid credentials. Try again.\n";
        return false;
    }

    bool managementLogin() {
        cout << "Enter management username: ";
        string username, password;
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        // Clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (managementCredentials.find(username) != managementCredentials.end() &&
            managementCredentials[username] == password) {
            cout << "Management login successful!\n";
            return true;
        }
        cout << "Invalid credentials. Try again.\n";
        return false;
    }
};

// Menu for Student options
void studentMenu(Student &student, Management &mgmt, Mess &mess, Sports &sports) {
    int choice;
    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. View Hostel Details\n"; //  View Hostel Details
        cout << "2. View Mess Details\n";
        cout << "3. View Sports Details\n";
        cout << "4. Lodge Complaint\n";
        cout << "5. Request IT Service\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.clear();            
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                student.viewHostelDetails(mgmt); // Call for view hostel details
                break;
            case 2:
                student.viewMessDetails(mess);
                break;
            case 3:
                student.viewSportsDetails(sports);
                break;
            case 4:
                student.lodgeComplaint(mgmt.getComplaintSystem());
                break;
            case 5:
                student.requestITService(mgmt.getITDepartment());
                break;
            case 6:
                cout << "Exiting Student Menu.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

// Menu for Management options
void managementMenu(Management &mgmt) {
    int choice;
    do {
        cout << "\n--- Management Menu ---\n";
        cout << "1. View All Rooms\n";
        cout << "2. View Complaints\n";
        cout << "3. View IT Requests\n";
        cout << "4. Assign Room\n";
        cout << "5. Vacate Room\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.clear();            
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                mgmt.viewAllRooms();
                break;
            case 2:
                mgmt.viewComplaints();
                break;
            case 3:
                mgmt.viewITRequests();
                break;
            case 4: {
                int room;
                string student;
                cout << "Enter room number: ";
                cin >> room;
                cin.ignore();  // Clear input buffer before reading string
                cout << "Enter student name: ";
                getline(cin, student);
                mgmt.assignRoom(room, student);
                break;
            }
            case 5: {
                int room;
                cout << "Enter room number: ";
                cin >> room;
                mgmt.vacateRoom(room);
                break;
            }
            case 6:
                cout << "Exiting Management Menu.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}



// Main function
int main() {
    Management mgmt;
    LoginSystem loginSys;
    string studentName;
    Mess mess;
    Sports sports;

    int userType;
    do {
        cout << "\n--- Hostel Management System ---\n";
        cout << "1. Management Login\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> userType;

        // Clear input buffer
        cin.clear();            
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (userType) {
            case 1:
                if (loginSys.managementLogin()) managementMenu(mgmt);
                break;
            case 2:
                if (loginSys.studentLogin(studentName)) {
                    Student student(studentName);
                    studentMenu(student, mgmt, mess, sports);
                }
                break;
            case 3:
                cout << "Exiting System.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (userType != 3);

    return 0;
}