#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Interface for Check-In Behavior
class CheckInBehavior {
public:
    virtual void checkIn(const std::string& name) = 0;
    virtual ~CheckInBehavior() = default;
};

// Concrete Check-In Behavior for Mentor
class MentorCheckIn : public CheckInBehavior {
public:
    void checkIn(const std::string& name) override {
        std::cout << name << " has checked in as Mentor." << std::endl;
    }
};

// Concrete Check-In Behavior for Mentee
class MenteeCheckIn : public CheckInBehavior {
public:
    void checkIn(const std::string& name) override {
        std::cout << name << " has checked in as Mentee." << std::endl;
    }
};

// Base Class (Person) - Abstract Class
class Person {
protected:
    std::string name;
    std::string contactNumber;
    bool availability;
    CheckInBehavior* checkInBehavior;  // Composition for behavior

public:
    // Constructor
    Person(CheckInBehavior* behavior) : availability(false), checkInBehavior(behavior) {}

    // Virtual Destructor
    virtual ~Person() { delete checkInBehavior; }

    // Accessor and Mutator Methods
    std::string getName() const { return name; }
    void setName(const std::string& personName) { name = personName; }

    std::string getContactNumber() const { return contactNumber; }
    void setContactNumber(const std::string& personContact) { contactNumber = personContact; }

    bool isAvailable() const { return availability; }

    // Delegated check-in method (uses the strategy object)
    virtual void checkIn() {
        availability = true;
        checkInBehavior->checkIn(name);
    }

    virtual void checkOut() {
        availability = false;
        std::cout << name << " has checked out." << std::endl;
    }

    virtual std::string getType() const = 0;
    virtual std::string getExpertise() const = 0;
};

// Derived Class: Mentor
class Mentor : public Person {
private:
    std::string type;
    std::string expertise;

public:
    // Constructor that sets Mentor-specific check-in behavior
    Mentor() : Person(new MentorCheckIn()) {}

    std::string getType() const override { return type; }
    void setType(const std::string& mentorType) { type = mentorType; }

    std::string getExpertise() const override { return expertise; }
    void setExpertise(const std::string& mentorExpertise) { expertise = mentorExpertise; }
};

// Derived Class: Mentee
class Mentee : public Person {
private:
    std::string type;
    std::string expertise;

public:
    // Constructor that sets Mentee-specific check-in behavior
    Mentee() : Person(new MenteeCheckIn()) {}

    std::string getType() const override { return type; }
    void setType(const std::string& menteeType) { type = menteeType; }

    std::string getExpertise() const override { return expertise; }
    void setExpertise(const std::string& menteeExpertise) { expertise = menteeExpertise; }
};

// Manager Class: PersonManager (Supports LSP)
class PersonManager {
private:
    static std::vector<Person*> personList;

public:
    static void addPerson(Person* person) {
        personList.push_back(person);
    }

    static void displayPersons() {
        std::cout << "List of Persons:" << std::endl;
        for (const auto& person : personList) {
            std::cout << "Name: " << person->getName() << ", Type: " << person->getType()
                      << ", Expertise: " << person->getExpertise()
                      << ", Contact: " << person->getContactNumber() << std::endl;
        }
    }
};

std::vector<Person*> PersonManager::personList;

// Main function
int main() {
    int personType;
    std::string name, contact, type, expertise;

    std::cout << "Enter details for Mentor or Mentee\n";

    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter 1 for Mentor, 2 for Mentee: ";
        std::cin >> personType;
        std::cin.ignore();

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Enter contact number: ";
        std::getline(std::cin, contact);

        std::cout << "Enter type (Technical/Program): ";
        std::getline(std::cin, type);

        std::cout << "Enter expertise: ";
        std::getline(std::cin, expertise);

        if (personType == 1) {
            Mentor* mentor = new Mentor();
            mentor->setName(name);
            mentor->setContactNumber(contact);
            mentor->setType(type);
            mentor->setExpertise(expertise);
            mentor->checkIn();
            PersonManager::addPerson(mentor);
        } else if (personType == 2) {
            Mentee* mentee = new Mentee();
            mentee->setName(name);
            mentee->setContactNumber(contact);
            mentee->setType(type);
            mentee->setExpertise(expertise);
            mentee->checkIn();
            PersonManager::addPerson(mentee);
        } else {
            std::cout << "Invalid option. Please enter either 1 or 2." << std::endl;
        }
    }

    PersonManager::displayPersons();

    return 0;
}
