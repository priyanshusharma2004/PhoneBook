#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Contact {
private:
    string name;
    string phoneNumber;
public:
    Contact(string name, string phoneNumber)
        : name(name), phoneNumber(phoneNumber) {}
    string getName() const {
        return name;
    }
    string getPhoneNumber() const {
        return phoneNumber;
    }
    void displayContact() const {
        cout << "Name: " << name << ", Phone Number: " << phoneNumber << endl;
    }
};
class ContactBook {
private:
    vector<Contact> contacts;
public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully." << endl;
    }
    void displayAllContacts() const {
        cout << "All Contacts:" << endl;
        for (const Contact& contact : contacts) {
            contact.displayContact();
        }
    }
    void searchContact(const string& name) const {
        bool found = false;
        cout << "Search Results:" << endl;
        for (const Contact& contact : contacts) {
            if (contact.getName() == name) {
                contact.displayContact();
                found = true;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }
};
int main() {
    ContactBook contactBook;
    int choice;
    string name, phoneNumber;
    while (true) {
        cout << "\nContact Book App" << endl;
        cout << "1. Add Contact\n2. Display All Contacts\n3. Search Contact\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                contactBook.addContact(Contact(name, phoneNumber));
                break;
            case 2:
                contactBook.displayAllContacts();
                break;
            case 3:
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, name);
                contactBook.searchContact(name);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}