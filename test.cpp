#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Base Class
//Base Class (Person):
// This class will have attributes and methods common to both Mentor and Mentee.


class Person {
protected:
    std::string name;
    std::string contactNumber;
    bool availability;

public:
    // Constructor
    Person() : availability(false) {}

    // Destructor
    virtual ~Person() {}

    // Accessor and Mutator Methods
    std::string getName() const { return name; }
    void setName(const std::string& personName) { name = personName; }

    std::string getContactNumber() const { return contactNumber; }
    void setContactNumber(const std::string& personContact) { contactNumber = personContact; }

    bool isAvailable() const { return availability; }

    // Method to check-in a person
    void checkIn() {
        availability = true;
        std::cout << name << " has checked in." << std::endl;
    }

    // Method to check-out a person
    void checkOut() {
        availability = false;
        std::cout << name << " has checked out." << std::endl;
    }
};

// Derived Class: Mentor
// 2. Derived Classes (Mentor and Mentee):
//Both Mentor and Mentee inherit from Person, demonstrating single inheritance. 
//Mentor and Mentee also add their specific attributes, demonstrating hierarchical inheritance.
class Mentor : public Person {
private:
    std::string type; // Technical or Program
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
    std::string type; // Technical or Program
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
    // Creating Mentor objects
    Mentor mentor1;
    mentor1.setName("Alice");
    mentor1.setContactNumber("123-456-7890");
    mentor1.setType("Technical");
    mentor1.setExpertise("C++");

    Mentor mentor2;
    mentor2.setName("Bob");
    mentor2.setContactNumber("987-654-3210");
    mentor2.setType("Program");
    mentor2.setExpertise("Java");

    // Creating Mentee objects
    Mentee mentee1;
    mentee1.setName("Charlie");
    mentee1.setContactNumber("111-222-3333");
    mentee1.setType("Technical");
    mentee1.setExpertise("Python");

    Mentee mentee2;
    mentee2.setName("David");
    mentee2.setContactNumber("444-555-6666");
    mentee2.setType("Program");
    mentee2.setExpertise("Data Science");

    // Checking in mentors and mentees
    mentor1.checkIn();
    mentee1.checkIn();

    // Display lists of Mentors and Mentees
    Mentor::displayMentors();
    Mentee::displayMentees();

    // Display counts
    std::cout << "Total Mentors: " << Mentor::getMentorCount() << std::endl;
    std::cout << "Total Mentees: " << Mentee::getMenteeCount() << std::endl;

    // Checking out a person
    mentor1.checkOut();
    mentee1.checkOut();

    return 0;
}

