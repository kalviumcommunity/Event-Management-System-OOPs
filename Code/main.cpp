#include <iostream>
#include <string>

using namespace std;

class Event {
public:
    Event() {}

    Event(string eventName, string organization, string type, string venue)
        : eventName(eventName), organization(organization), type(type), venue(venue) {}

    void displayEventDetails() const {
        cout << "Event Name: " << eventName << endl;
        cout << "Organization: " << organization << endl;
        cout << "Type: " << type << endl;
        cout << "Venue: " << venue << endl;
    }

private:
    string eventName;
    string organization;
    string type;
    string venue;
};

class University {
public:
    virtual void displayUniversityName() const = 0;
    virtual void displayEvents() const = 0;

    virtual ~University() {}
};

class LovelyProfessionalUniversity : public University {
public:
    LovelyProfessionalUniversity() : numEvents(0) {
        addEvent("TechnOcean", "Apna College", "Tech", "Block of Computer Science and Engineering");
        addEvent("Sukoon", "Oasis", "Cultural", "Shanti Devi Mittal Auditorium");
        addEvent("One India", "Untangle", "Cultural", "BaldevRaj Mittal UniPolis");
        addEvent("Coke Studio Concert", "Division Of Student Welfare", "Entertainment", "BaldevRaj Mittal UniPolis");
    }

    void displayUniversityName() const {
        cout << "Lovely Professional University";
    }

    void displayEvents() const {
        cout << "Upcoming Events at Lovely Professional University:" << endl << endl;
        for (int i = 0; i < numEvents; i++) {
            cout << "Event #" << (i + 1) << ":" << endl;
            events[i].displayEventDetails();
            cout << endl;
        }
    }

private:
    static const int MAX_EVENTS = 10;
    Event events[MAX_EVENTS];
    int numEvents;

    void addEvent(string eventName, string organization, string type, string venue) {
        if (numEvents < MAX_EVENTS) {
            events[numEvents] = Event(eventName, organization, type, venue);
            numEvents++;
        } else {
            cout << "Event list is full. Cannot add more events." << endl;
        }
    }
};

class RevaUniversity : public University {
public:
    RevaUniversity() : numEvents(0) {
        addEvent("Science Expo", "Untangle", "Science", "Swami Vivekananda Exhibition Hall");
        addEvent("Chandan Shetty Concert", "Spade", "Music", "Sougandhika");
        addEvent("Revaotsav", "Reva", "Cultural", "Sougandhika");
        addEvent("RevaSangama", "Reva", "Cultural", "Kuvempu Auditorium");
    }

    void displayUniversityName() const {
        cout << "Reva University";
    }

    void displayEvents() const {
        cout << "Upcoming Events at Reva University:" << endl << endl;
        for (int i = 0; i < numEvents; i++) {
            cout << "Event #" << (i + 1) << ":" << endl;
            events[i].displayEventDetails();
            cout << endl;
        }
    }

private:
    static const int MAX_EVENTS = 10;
    Event events[MAX_EVENTS];
    int numEvents;

    void addEvent(string eventName, string organization, string type, string venue) {
        if (numEvents < MAX_EVENTS) {
            events[numEvents] = Event(eventName, organization, type, venue);
            numEvents++;
        } else {
            cout << "Event list is full. Cannot add more events." << endl;
        }
    }
};

class Greeting {
public:
    Greeting() {
        lpu = new LovelyProfessionalUniversity();
        reva = new RevaUniversity();
    }

    ~Greeting() {
        delete lpu;
        delete reva;
    }

    void askName() {
        cout << "Please enter your name: ";
        cin >> this->name;
    }

    void printGreeting() {
        cout << "Hello, " << this->name << "! Nice to have you on our platform ..." << endl << endl;
    }

    void universitySelection() {
        while (true) {
            cout << "Please select the university in which you would like to attend the event" << endl << endl;
            cout << "1. Lovely Professional University" << endl;
            cout << "2. Reva University" << endl << endl;
            cout << "Enter the number of your choice: ";
            cin >> this->choice;

            if (this->choice == 1 || this->choice == 2) {
                break;
            } else {
                cout << "🚫Invalid choice of University🚫" << endl << " Please try again!!" << endl << endl;
            }
        }
    }

    void universitySelected() {
        switch (this->choice) {
            case 1:
                cout << "You selected ";
                lpu->displayUniversityName();
                cout << " and These are the ";
                lpu->displayEvents();
                break;
            case 2:
                cout << "You selected ";
                reva->displayUniversityName();
                cout << " and These are the ";
                reva->displayEvents();
                break;
        }
    }

private:
    string name;
    int choice;
    University* lpu;
    University* reva;
};

int main() {
    Greeting userGreeting;

    userGreeting.askName();
    userGreeting.printGreeting();
    userGreeting.universitySelection();
    userGreeting.universitySelected();

    return 0;
}