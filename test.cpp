#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Base Class (Person)
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

    // Virtual method to check-in a person (can be overridden)
    virtual void checkIn() {
        availability = true;
        std::cout << name << " has checked in (Person)." << std::endl;
    }

    // Virtual method to check-out a person (can be overridden)
    virtual void checkOut() {
        availability = false;
        std::cout << name << " has checked out (Person)." << std::endl;
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

    // Overloaded setExpertise method (Compile-time Polymorphism)
    void setExpertise(const std::string& mentorExpertise) { expertise = mentorExpertise; }
    void setExpertise(const char* mentorExpertise) { expertise = std::string(mentorExpertise); }

    // Overriding checkIn (Runtime Polymorphism)
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

    // Overriding checkIn (Runtime Polymorphism)
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
    // Demonstrating Polymorphism
    Person* people[2];

    Mentor mentor1;
    mentor1.setName("Alice");
    mentor1.setContactNumber("123-456-7890");
    mentor1.setType("Technical");
    mentor1.setExpertise("C++");

    Mentee mentee1;
    mentee1.setName("Charlie");
    mentee1.setContactNumber("111-222-3333");
    mentee1.setType("Technical");
    mentee1.setExpertise("Python");

    // Array of base class pointers for polymorphic behavior
    people[0] = &mentor1;
    people[1] = &mentee1;

    // Demonstrating runtime polymorphism
    for (int i = 0; i < 2; ++i) {
        people[i]->checkIn(); // Calls the overridden checkIn method
    }

    // Display lists of Mentors and Mentees
    Mentor::displayMentors();
    Mentee::displayMentees();

    return 0;
}
