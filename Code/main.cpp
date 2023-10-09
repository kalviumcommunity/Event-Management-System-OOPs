#include <iostream>
#include <string>

using namespace std;

// Class to represent a particular event !!
class Event {
public:
    Event() {} // Default constructor

    Event(string eventName, string organization, string type, string venue) : eventName(eventName) , organization(organization), type(type), venue(venue) {}

    void displayEventDetails() {
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

// Class to hold all the events
class Events {
public:
    Events(int maxSize) : maxSize(maxSize), numEvents(0) {
        events = new Event[maxSize];
    }

    ~Events() {
        delete[] events;
    }

    void addEvent(string eventName, string organization, string type, string venue) {
        if (numEvents < maxSize) {
            events[numEvents] = Event(eventName, organization, type, venue);
            numEvents++;
        } else {
            cout << "Event list is full. Cannot add more events." << endl;
        }
    }

    void displayEvents() {
        cout << "Upcoming Events:" << endl << endl;
        for (int i = 0; i < numEvents; i++) {
            cout << "Event #" << (i + 1) << ":" << endl;
            events[i].displayEventDetails();
            cout << endl;
        }
    }

private:
    int maxSize;
    int numEvents;
    Event* events;
};

class Greeting {
public:
    Greeting() {
        // Initialize the events for each university using dynamic memory allocation
        lpuEvents = new Events(MAX_EVENTS);
        revaEvents = new Events(MAX_EVENTS);

        lpuEvents->addEvent("TechnOcean", "Apna College", "Tech", "Block of Computer Science and Engeneering");
        lpuEvents->addEvent("Sukoon", "Oasis", "Cultural", "Shanti Devi Mittal Auditorium");

        revaEvents->addEvent("Science Expo", "Untangle", "Science", "Swami Vivekananda Exhibition Hall");
        revaEvents->addEvent("Chandan Shetty Concert", "Spade", "Music", "Sougandhika");
    }

    ~Greeting() {
        delete lpuEvents;
        delete revaEvents;
    }

    void askName() {
        cout << "Please enter your name: ";
        cin >> this->name;
    }

    void printGreeting() {
        cout << "Hello, " << this->name << " ! Nice to have you on our platform ..." << endl << endl;
    }

    void universitySelection() {
        while (true) {
            cout << "Please select the university in which you would like to attend the event" << endl << endl;
            cout << "1. Lovely Professional University" << endl;
            cout << "2. Reva University" << endl << endl;
            cout << "Enter the number of your choice: ";
            cin >> this->choice;

            if (this->choice == 1 || this->choice == 2) {
                break;  // Valid choice, exit the loop
            } else {
                cout << "🚫Invalid choice of University🚫" << endl << " Please try again!!" << endl << endl;
            }
        }
    }

    void universitySelected() {
        switch (this->choice) {
            case 1:
                cout << "You selected Lovely Professional University and These are the ";
                lpuEvents->displayEvents();
                break;
            case 2:
                cout << "You selected Reva University and These are the ";
                revaEvents->displayEvents();
                break;
        }
    }

private:
    string name;
    int choice;
    static const int MAX_EVENTS = 10; // Maximum number of events per university
    Events* lpuEvents;
    Events* revaEvents;
};

int main() {
    Greeting userGreeting;

    userGreeting.askName();
    userGreeting.printGreeting();
    userGreeting.universitySelection();
    userGreeting.universitySelected();

    return 0;
}