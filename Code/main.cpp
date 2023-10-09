#include <iostream>
#include <string>

using namespace std;

class Greeting {
public:
    void askName() {
        cout << "Please enter your name: ";
        cin >> name;
    }

    void printGreeting() {
        cout << "Hello, " << name << "! Nice to have you on our platform !!" << endl << endl;
    }

    void universitySelection() {
        while (true) {
            cout << "Please select the university in which you would like to attend the event" << endl << endl;
            cout << "1. Lovely Professional University" << endl;
            cout << "2. Reva University" << endl << endl;
            cout << "Enter the number of your choice: ";
            cin >> choice;

            if (choice == 1 || choice == 2) {
                break;  // Valid choice, exit the loop
            } else {
                cout << "Invalid choice of University. Please try again." << endl;
            }
        }
    }

    void universitySelected() {
        switch (choice) {
            case 1:
                cout << "You selected Lovely Professional University and These are the Upcoming Events !!" << endl;
                break;
            case 2:
                cout << "You selected Reva University and These are the Upcoming Events !!" << endl;
                break;
            default:
                cout << "Invalid choice of University." << endl;
                break;
        }
    }

private:
    string name;
    int choice;
};

int main() {
    Greeting userGreeting;

    userGreeting.askName();
    userGreeting.printGreeting();
    userGreeting.universitySelection();
    userGreeting.universitySelected();

    return 0;
}
