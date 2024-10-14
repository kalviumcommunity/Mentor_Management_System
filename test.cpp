#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Base Class (Person) - Abstract Class
class Person {
protected:
    std::string name;
    std::string contactNumber;
    bool availability;

public:
    // Constructor
    Person() : availability(false) {}

    // Virtual Destructor (important in abstract classes)
    virtual ~Person() {}

    // Accessor and Mutator Methods
    std::string getName() const { return name; }
    void setName(const std::string& personName) { name = personName; }

    std::string getContactNumber() const { return contactNumber; }
    void setContactNumber(const std::string& personContact) { contactNumber = personContact; }

    bool isAvailable() const { return availability; }

    // Pure virtual method - makes Person an abstract class
    virtual void checkIn() = 0;  // Must be implemented in derived classes

    // Virtual method for checking out a person
    virtual void checkOut() {
        availability = false;
        std::cout << name << " has checked out." << std::endl;
    }
};

// Derived Class: Mentor
class Mentor : public Person {
private:
    std::string type;  // Technical or Program
    std::string expertise;

    static int mentorCount;
    static std::vector<Mentor*> mentorList;

public:
    // Constructor
    Mentor() {
        ++mentorCount;
        mentorList.push_back(this);
    }

    // Destructor
    ~Mentor() {
        --mentorCount;
        auto it = std::find(mentorList.begin(), mentorList.end(), this);
        if (it != mentorList.end()) {
            mentorList.erase(it);
        }
    }

    // Accessor and Mutator Methods for Mentor-specific attributes
    std::string getType() const { return type; }
    void setType(const std::string& mentorType) { type = mentorType; }

    std::string getExpertise() const { return expertise; }
    void setExpertise(const std::string& mentorExpertise) { expertise = mentorExpertise; }

    // Overriding pure virtual method checkIn from Person (Runtime Polymorphism)
    void checkIn() override {
        availability = true;
        std::cout << name << " has checked in as Mentor." << std::endl;
    }

    // Static function to display all mentors
    static void displayMentors() {
        std::cout << "List of Mentors:" << std::endl;
        for (const auto& mentor : mentorList) {
            std::cout << "Name: " << mentor->getName() << ", Type: " << mentor->getType() 
                      << ", Expertise: " << mentor->getExpertise() 
                      << ", Contact: " << mentor->getContactNumber() << std::endl;
        }
    }

    // Static function to get the total number of mentors
    static int getMentorCount() {
        return mentorCount;
    }
};

// Static member initialization for Mentor class
int Mentor::mentorCount = 0;
std::vector<Mentor*> Mentor::mentorList;

// Derived Class: Mentee
class Mentee : public Person {
private:
    std::string type;  // Technical or Program
    std::string expertise;

    static int menteeCount;
    static std::vector<Mentee*> menteeList;

public:
    // Constructor
    Mentee() {
        ++menteeCount;
        menteeList.push_back(this);
    }

    // Destructor
    ~Mentee() {
        --menteeCount;
        auto it = std::find(menteeList.begin(), menteeList.end(), this);
        if (it != menteeList.end()) {
            menteeList.erase(it);
        }
    }

    // Accessor and Mutator Methods for Mentee-specific attributes
    std::string getType() const { return type; }
    void setType(const std::string& menteeType) { type = menteeType; }

    std::string getExpertise() const { return expertise; }
    void setExpertise(const std::string& menteeExpertise) { expertise = menteeExpertise; }

    // Overriding pure virtual method checkIn from Person (Runtime Polymorphism)
    void checkIn() override {
        availability = true;
        std::cout << name << " has checked in as Mentee." << std::endl;
    }

    // Static function to display all mentees
    static void displayMentees() {
        std::cout << "List of Mentees:" << std::endl;
        for (const auto& mentee : menteeList) {
            std::cout << "Name: " << mentee->getName() << ", Type: " << mentee->getType() 
                      << ", Expertise: " << mentee->getExpertise() 
                      << ", Contact: " << mentee->getContactNumber() << std::endl;
        }
    }

    // Static function to get the total number of mentees
    static int getMenteeCount() {
        return menteeCount;
    }
};

// Static member initialization for Mentee class
int Mentee::menteeCount = 0;
std::vector<Mentee*> Mentee::menteeList;

// Main function
int main() {
    int personType;
    std::string name, contact, type, expertise;

    std::cout << "Enter details for Mentor or Mentee\n";
    
    // Loop to handle multiple people input
    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter 1 for Mentor, 2 for Mentee: ";
        std::cin >> personType;
        std::cin.ignore();  // Ignore any newline characters left in the input buffer

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Enter contact number: ";
        std::getline(std::cin, contact);

        std::cout << "Enter type (Technical/Program): ";
        std::getline(std::cin, type);

        std::cout << "Enter expertise: ";
        std::getline(std::cin, expertise);

        if (personType == 1) {
            // Create a Mentor
            Mentor* mentor = new Mentor();
            mentor->setName(name);
            mentor->setContactNumber(contact);
            mentor->setType(type);
            mentor->setExpertise(expertise);
            mentor->checkIn();
        } else if (personType == 2) {
            // Create a Mentee
            Mentee* mentee = new Mentee();
            mentee->setName(name);
            mentee->setContactNumber(contact);
            mentee->setType(type);
            mentee->setExpertise(expertise);
            mentee->checkIn();
        } else {
            std::cout << "Invalid option. Please enter either 1 or 2." << std::endl;
        }
    }

    // Display lists of Mentors and Mentees
    Mentor::displayMentors();
    Mentee::displayMentees();

    return 0;
}
