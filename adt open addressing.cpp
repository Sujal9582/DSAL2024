#include <iostream>
#include <string>

using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
    
    Node(string k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    Node* table[TABLE_SIZE];
    
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }
    
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }
    
    void Insert(const string& key, int value) {
        int index = hashFunction(key);
        
        switch (table[index] == nullptr) {
            case true:
                table[index] = new Node(key, value);
                break;
            case false:
                Node* temp = table[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new Node(key, value);
                break;
        }
    }
    
    int Find(const string& key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        
        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        
        return -1;
    }
    
    void Delete(const string& key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        
        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }
        
        if (temp != nullptr) {
            switch (prev == nullptr) {
                case true:
                    table[index] = temp->next;
                    break;
                case false:
                    prev->next = temp->next;
                    break;
            }
            delete temp;
        }
    }
    
    void Display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    HashTable dictionary;
    int choice;
    string key;
    int value;
    
    do {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dictionary.Insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                value = dictionary.Find(key);
                if (value != -1) {
                    cout << "Value found: " << value << endl;
                } else {
                    cout << "Key not found.\n";
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.Delete(key);
                cout << "Key deleted.\n";
                break;
            case 4:
                cout << "Hash Table Contents:\n";
                dictionary.Display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);
    
    return 0;
}
