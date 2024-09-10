#include <iostream>
#include <string>
#include <vector>

class Mentor {
private:
    std::string name;
    std::string type; // Technical or Program
    std::string expertise;
    std::string contactNumber;
    bool availability;

    // Static variable to keep track of the number of Mentors
    static int mentorCount;
    static std::vector<Mentor*> mentorList; // Static vector to hold all Mentor instances

public:
    Mentor() : availability(false) {
        ++mentorCount; // Increment the static count when a Mentor is created
        mentorList.push_back(this); // Add this Mentor to the list
    }

    // Destructor to decrement the static count when a Mentor is deleted
    ~Mentor() {
        --mentorCount;
        mentorList.erase(std::remove(mentorList.begin(), mentorList.end(), this), mentorList.end()); // Remove this Mentor from the list
    }

    // Static method to display all mentors
    static void displayMentors() {
        std::cout << "List of Mentors:" << std::endl;
        for (const auto& mentor : mentorList) {
            std::cout << "Name: " << mentor->getName() << ", Type: " << mentor->getType() 
                      << ", Expertise: " << mentor->getExpertise() 
                      << ", Contact: " << mentor->getContactNumber() << std::endl;
        }
    }

    // Accessor methods (Getters)
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    std::string getExpertise() const { return expertise; }
    std::string getContactNumber() const { return contactNumber; }
    bool isAvailable() const { return availability; }

    // Mutator methods (Setters)
    void setName(const std::string& mentorName) { name = mentorName; }
    void setType(const std::string& mentorType) { type = mentorType; }
    void setExpertise(const std::string& mentorExpertise) { expertise = mentorExpertise; }
    void setContactNumber(const std::string& mentorContact) { contactNumber = mentorContact; }

    // Method to check-in a mentor
    void checkIn() {
        this->availability = true;
        std::cout << this->name << " has checked in." << std::endl;
    }

    // Method to check-out a mentor
    void checkOut() {
        this->availability = false;
        std::cout << this->name << " has checked out." << std::endl;
    }

    // Static method to get the current number of Mentors
    static int getMentorCount() {
        return mentorCount;
    }
};

// Initialize the static variables
int Mentor::mentorCount = 0;
std::vector<Mentor*> Mentor::mentorList;

class Mentee {
private:
    std::string name;
    std::string type; // Technical or Program
    std::string expertise;
    std::string contactNumber;
    bool availability;

    // Static variable to keep track of the number of Mentees
    static int menteeCount;
    static std::vector<Mentee*> menteeList; // Static vector to hold all Mentee instances

public:
    Mentee() : availability(false) {
        ++menteeCount; // Increment the static count when a Mentee is created
        menteeList.push_back(this); // Add this Mentee to the list
    }

    // Destructor to decrement the static count when a Mentee is deleted
    ~Mentee() {
        --menteeCount;
        menteeList.erase(std::remove(menteeList.begin(), menteeList.end(), this), menteeList.end()); // Remove this Mentee from the list
    }

    // Static method to display all mentees
    static void displayMentees() {
        std::cout << "List of Mentees:" << std::endl;
        for (const auto& mentee : menteeList) {
            std::cout << "Name: " << mentee->getName() << ", Type: " << mentee->getType() 
                      << ", Expertise: " << mentee->getExpertise() 
                      << ", Contact: " << mentee->getContactNumber() << std::endl;
        }
    }

    // Accessor methods (Getters)
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    std::string getExpertise() const { return expertise; }
    std::string getContactNumber() const { return contactNumber; }
    bool isAvailable() const { return availability; }

    // Mutator methods (Setters)
    void setName(const std::string& menteeName) { name = menteeName; }
    void setType(const std::string& menteeType) { type = menteeType; }
    void setExpertise(const std::string& menteeExpertise) { expertise = menteeExpertise; }
    void setContactNumber(const std::string& menteeContact) { contactNumber = menteeContact; }

    // Method to check-in a mentee
    void checkIn() {
        this->availability = true;
        std::cout << this->name << " has checked in." << std::endl;
    }

    // Method to check-out a mentee
    void checkOut() {
        this->availability = false;
        std::cout << this->name << " has checked out." << std::endl;
    }

    // Static method to get the current number of Mentees
    static int getMenteeCount() {
        return menteeCount;
    }
};

// Initialize the static variables
int Mentee::menteeCount = 0;
std::vector<Mentee*> Mentee::menteeList;

int main() {
    const int size = 2;

    // Creating an array of Mentor objects dynamically
    Mentor* mentors = new Mentor[size];

    for (int i = 0; i < size; ++i) {
        std::string name, type, expertise, contactNumber;

        std::cout << "Enter Mentor " << i + 1 << "'s Name: ";
        std::getline(std::cin, name);
        mentors[i].setName(name);

        std::cout << "Enter Mentor " << i + 1 << "'s Type (Technical/Program): ";
        std::getline(std::cin, type);
        mentors[i].setType(type);

        std::cout << "Enter Mentor " << i + 1 << "'s Expertise: ";
        std::getline(std::cin, expertise);
        mentors[i].setExpertise(expertise);

        std::cout << "Enter Mentor " << i + 1 << "'s Contact Number: ";
        std::getline(std::cin, contactNumber);
        mentors[i].setContactNumber(contactNumber);
    }

    // Creating an array of Mentee objects dynamically
    Mentee* mentees = new Mentee[size];
    for (int i = 0; i < size; ++i) {
        std::string name, type, expertise, contactNumber;

        std::cout << "Enter Mentee " << i + 1 << "'s Name: ";
        std::getline(std::cin, name);
        mentees[i].setName(name);

        std::cout << "Enter Mentee " << i + 1 << "'s Type (Technical/Program): ";
        std::getline(std::cin, type);
        mentees[i].setType(type);

        std::cout << "Enter Mentee " << i + 1 << "'s Expertise: ";
        std::getline(std::cin, expertise);
        mentees[i].setExpertise(expertise);

        std::cout << "Enter Mentee " << i + 1 << "'s Contact Number: ";
        std::getline(std::cin, contactNumber);
        mentees[i].setContactNumber(contactNumber);
    }

    // Checking in the mentors
    for (int i = 0; i < size; ++i) {
        mentors[i].checkIn();
    }

    // Checking in the mentees
    for (int i = 0; i < size; ++i) {
        mentees[i].checkIn();
    }

    // Display the list of mentors and mentees
    Mentor::displayMentors();
    Mentee::displayMentees();

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

    // Free the dynamically allocated memory
    delete[] mentors;
    delete[] mentees;

    return 0;
}

