#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string name;
    string phone;

    Contact(const string& name, const string& phone) : name(name), phone(phone) {}
};

class Phonebook {
private:
    vector<Contact> contacts;

public:
    void addContact(const string& name, const string& phone) {
        Contact contact(name, phone);
        contacts.push_back(contact);
        sortContacts();
        cout << "Contact added successfully." << endl;
    }

    void searchContact(const string& name) {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Contact found:" << endl;
                cout << "Name: " << contact.name << endl;
                cout << "Phone: " << contact.phone << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "Phonebook is empty." << endl;
        } else {
            cout << "Phonebook contacts:" << endl;
            for (const auto& contact : contacts) {
                cout << "Name: " << contact.name << endl;
                cout << "Phone: " << contact.phone << endl;
                cout << endl;
            }
        }
    }

private:
    void sortContacts() {
        int n = contacts.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (contacts[j].name > contacts[j + 1].name) {
                    swap(contacts[j], contacts[j + 1]);
                }
            }
        }
    }
};

int main() {
    Phonebook phonebook;
    int choice;
    string name, phone;
    cout<<"**************************Project Title: PhoneBook**************************/n/n/n/n/n/n"<<endl;
    cout<<"**************************THIS PROGRAM IS MADE BY***************************"<<endl;
    cout<<"**************************Muhammad Furqan Nasir*****************************"<<endl;

    do {
        cout << "Phonebook Menu" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Display Contacts" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter contact name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter contact phone number: ";
                cin >> phone;
                phonebook.addContact(name, phone);
                break;
            case 2:
                cout << "Enter contact name to search: ";
                cin.ignore();
                getline(cin, name);
                phonebook.searchContact(name);
                break;
            case 3:
                phonebook.displayContacts();
                break;
            case 4:
                cout << "Exiting Phonebook. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        cout << endl;
    } while (choice != 4);

    return 0;
}
