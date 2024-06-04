#include<string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularSinglyLinkedList {
private:
    Node* head;

public:
    CircularSinglyLinkedList() : head(nullptr) {}

    ~CircularSinglyLinkedList() {
        // Destructor to free the allocated memory
        Node* current = head;
        Node* nextNode;
        if (head) {
            do {
                nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
            head = nullptr;  // Set head to nullptr after deleting nodes
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << "[" << temp->data << ":" << temp << "] -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "Head\n";
    }

    void create() {
        // Create a sample circular linked list for demonstration
        insertAtEnd(1);
        insertAtEnd(2);
        insertAtEnd(3);
        insertAtEnd(4);
        insertAtEnd(5);
        // Make the list circular
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head;
    }

    // ... Other methods remain the same ...
};

int main() {
    CircularSinglyLinkedList myList;
    myList.create();

    // ... Other main function code remains the same ...

    return 0;
}
