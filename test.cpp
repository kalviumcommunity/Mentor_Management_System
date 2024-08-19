#include <iostream>
#include <string>

class Mentor {
public:
    std::string name;
    std::string type; // Technical or Program
    std::string expertise;
    std::string contactNumber;
    bool availability;

    // Static variable to keep track of the number of Mentors
    static int mentorCount;

    Mentor() : availability(false) {
        ++mentorCount; // Increment the static count when a Mentor is created
    }

    // Destructor to decrement the static count when a Mentor is deleted
    ~Mentor() {
        --mentorCount;
    }

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

    // Static method to get the current number of Mentors
    static int getMentorCount() {
        return mentorCount;
    }
};

// Initialize the static variable
int Mentor::mentorCount = 0;

class Mentee {
public:
    std::string name;
    std::string type; // Technical or Program
    std::string expertise;
    std::string contactNumber;
    bool availability;

    // Static variable to keep track of the number of Mentees
    static int menteeCount;

    Mentee() : availability(false) {
        ++menteeCount; // Increment the static count when a Mentee is created
    }

    // Destructor to decrement the static count when a Mentee is deleted
    ~Mentee() {
        --menteeCount;
    }

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

    // Static method to get the current number of Mentees
    static int getMenteeCount() {
        return menteeCount;
    }
};

// Initialize the static variable
int Mentee::menteeCount = 0;

int main() {
    const int size = 2;

    // Creating an array of Mentor objects dynamically
    Mentor* mentors = new Mentor[size];
    
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter Mentor " << i + 1 << "'s Name: ";
        std::getline(std::cin, mentors[i].name);
        std::cout << "Enter Mentor " << i + 1 << "'s Type (Technical/Program): ";
        std::getline(std::cin, mentors[i].type);
        std::cout << "Enter Mentor " << i + 1 << "'s Expertise: ";
        std::getline(std::cin, mentors[i].expertise);
        std::cout << "Enter Mentor " << i + 1 << "'s Contact Number: ";
        std::getline(std::cin, mentors[i].contactNumber);
    }

    // Creating an array of Mentee objects dynamically
    Mentee* mentees = new Mentee[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter Mentee " << i + 1 << "'s Name: ";
        std::getline(std::cin, mentees[i].name);
        std::cout << "Enter Mentee " << i + 1 << "'s Type (Technical/Program): ";
        std::getline(std::cin, mentees[i].type);
        std::cout << "Enter Mentee " << i + 1 << "'s Expertise: ";
        std::getline(std::cin, mentees[i].expertise);
        std::cout << "Enter Mentee " << i + 1 << "'s Contact Number: ";
        std::getline(std::cin, mentees[i].contactNumber);
    }

    // Checking in the mentors
    for (int i = 0; i < size; ++i) {
        mentors[i].checkIn();
    }

    // Checking in the mentees
    for (int i = 0; i < size; ++i) {
        mentees[i].checkIn();
    }

    // Checking out the mentors
    for (int i = 0; i < size; ++i) {
        mentors[i].checkOut();
    }

    // Checking out the mentees
    for (int i = 0; i < size; ++i) {
        mentees[i].checkOut();
    }

    // Display the number of mentors and mentees
    std::cout << "Current number of Mentors: " << Mentor::getMentorCount() << std::endl;
    std::cout << "Current number of Mentees: " << Mentee::getMenteeCount() << std::endl;

    // Deleting dynamically allocated memory
    delete[] mentors;
    delete[] mentees;

    return 0;
}

