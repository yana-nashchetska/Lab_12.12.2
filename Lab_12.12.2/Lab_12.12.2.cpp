#include <iostream>
#include <string>
using namespace std;

struct Zodiac {
    string surname;
    string name;
    string zodiacSign;
    int birthday[3];
    Zodiac* next;
};

Zodiac* createNode() {
    Zodiac* newNode = new Zodiac;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Zodiac*& head) {
    Zodiac* newNode = createNode();

    cout << "Enter surname: ";
    cin >> newNode->surname;
    cout << "Enter name: ";
    cin >> newNode->name;
    cout << "Enter zodiac sign: ";
    cin >> newNode->zodiacSign;
    cout << "Enter birthday (day month year): ";
    cin >> newNode->birthday[0] >> newNode->birthday[1] >> newNode->birthday[2];

    if (head == nullptr) {
        head = newNode;
    }
    else if (newNode->birthday[2] < head->birthday[2] ||  // Sort by year
        (newNode->birthday[2] == head->birthday[2] && newNode->birthday[1] < head->birthday[1]) ||  // Sort by month
        (newNode->birthday[2] == head->birthday[2] && newNode->birthday[1] == head->birthday[1] && newNode->birthday[0] < head->birthday[0]))  // Sort by day
    {
        newNode->next = head;
        head = newNode;
    }
    else {
        Zodiac* current = head;
        while (current->next != nullptr &&
            (newNode->birthday[2] > current->next->birthday[2] ||  // Sort by year
                (newNode->birthday[2] == current->next->birthday[2] && newNode->birthday[1] > current->next->birthday[1]) ||  // Sort by month
                (newNode->birthday[2] == current->next->birthday[2] && newNode->birthday[1] == current->next->birthday[1] && newNode->birthday[0] > current->next->birthday[0])))  // Sort by day
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    cout << "Data inserted successfully.\n";
}

void displayList(Zodiac* head) {
    if (head == nullptr) {
        cout << "No records found.\n";
    }
    else {
        cout << "List of Zodiac records:\n";
        cout << "Surname\t\tName\t\tZodiac Sign\t\tBirthday\n";
        cout << "------------------------------------------------------\n";
        Zodiac* current = head;
        while (current != nullptr) {
            cout << current->surname << "\t\t" << current->name << "\t\t" << current->zodiacSign << "\t\t\t"
                << current->birthday[0] << "-" << current->birthday[1] << "-" << current->birthday[2] << "\n";
            current = current->next;
        }
    }
}

Zodiac* searchRecord(Zodiac* head, const string& surname) {
    Zodiac* current = head;
    while (current != nullptr) {
        if (current->surname == surname) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int main() {
    Zodiac* head = nullptr;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Insert a record\n";
        cout << "2. Display all records\n";
        cout << "3. Search for a record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertNode(head);
            break;
        case 2:
            displayList(head);
            break;
        case 3: {
            string searchSurname;
            cout << "Enter the surname to search for: ";
            cin >> searchSurname;
            Zodiac* foundRecord = searchRecord(head, searchSurname);
            if (foundRecord != nullptr) {
                cout << "Record found:\n";
                cout << "Surname\t\tName\t\tZodiac Sign\t\tBirthday\n";
                cout << "------------------------------------------------------\n";
                cout << foundRecord->surname << "\t\t" << foundRecord->name << "\t\t" << foundRecord->zodiacSign << "\t\t\t"
                    << foundRecord->birthday[0] << "-" << foundRecord->birthday[1] << "-" << foundRecord->birthday[2] << "\n";
            }
            else {
                cout << "Record not found.\n";
            }
        }
              break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
