#include <iostream>
#include <string>

class Mentor {
public:
    std::string name;
    std::string type; // Technical or Program
    std::string expertise;
    std::string contactNumber;
    bool availability;

    // Method to check-in a mentor
    void checkIn() {
        this->availability = true; // Using 'this' pointer
        std::cout << this->name << " has checked in." << std::endl; // Using 'this' pointer
    }

    // Method to check-out a mentor
    void checkOut() {
        this->availability = false; // Using 'this' pointer
        std::cout << this->name << " has checked out." << std::endl; // Using 'this' pointer
    }
};

class Mentee {
public:
    std::string name;
    std::string type; // Technical or Program
    std::string expertise;
    std::string contactNumber;
    bool availability;

    // Method to check-in a mentee
    void checkIn() {
        this->availability = true; // Using 'this' pointer
        std::cout << this->name << " has checked in." << std::endl; // Using 'this' pointer
    }

    // Method to check-out a mentee
    void checkOut() {
        this->availability = false; // Using 'this' pointer
        std::cout << this->name << " has checked out." << std::endl; // Using 'this' pointer
    }
};

int main() {
    // Creating a Mentor object
    Mentor mentor1;
    std::cout << "Enter Mentor's Name: ";
    std::getline(std::cin, mentor1.name);
    std::cout << "Enter Mentor's Type (Technical/Program): ";
    std::getline(std::cin, mentor1.type);
    std::cout << "Enter Mentor's Expertise: ";
    std::getline(std::cin, mentor1.expertise);
    std::cout << "Enter Mentor's Contact Number: ";
    std::getline(std::cin, mentor1.contactNumber);
    mentor1.availability = false;

    // Creating a Mentee object
    Mentee mentee1;
    std::cout << "Enter Mentee's Name: ";
    std::getline(std::cin, mentee1.name);
    std::cout << "Enter Mentee's Type (Technical/Program): ";
    std::getline(std::cin, mentee1.type);
    std::cout << "Enter Mentee's Expertise: ";
    std::getline(std::cin, mentee1.expertise);
    std::cout << "Enter Mentee's Contact Number: ";
    std::getline(std::cin, mentee1.contactNumber);
    mentee1.availability = false;

    // Checking in the mentor and mentee
    mentor1.checkIn();
    mentee1.checkIn();

    // Checking out the mentor and mentee
    mentor1.checkOut();
    mentee1.checkOut();

    return 0;
}

