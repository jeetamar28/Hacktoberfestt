#include <iostream>
#include <vector>
#include <string>

// Contact structure
struct Contact {
    std::string name;
    std::string phone;
};

// Function to add a contact
void addContact(std::vector<Contact>& contacts) {
    Contact contact;
    std::cout << "Enter name: ";
    std::cin >> contact.name;
    std::cout << "Enter phone number: ";
    std::cin >> contact.phone;
    contacts.push_back(contact);
    std::cout << "Contact added successfully!" << std::endl;
}

// Function to display all contacts
void displayContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts found." << std::endl;
        return;
    }
    std::cout << "Contacts:" << std::endl;
    for (const Contact& contact : contacts) {
        std::cout << "Name: " << contact.name << ", Phone: " << contact.phone << std::endl;
    }
}

// Function to search for a contact by name
void searchContact(const std::vector<Contact>& contacts, const std::string& name) {
    bool found = false;
    for (const Contact& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Contact found:" << std::endl;
            std::cout << "Name: " << contact.name << ", Phone: " << contact.phone << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Contact not found." << std::endl;
    }
}

int main() {
    std::vector<Contact> contacts;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                std::cout << "Enter name to search: ";
                std::string name;
                std::cin >> name;
                searchContact(contacts, name);
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
