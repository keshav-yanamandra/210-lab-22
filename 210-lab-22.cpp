// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 22

#include <iostream>
using namespace std;

//const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }
    
    //renaming delete node
    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    //adding pop_front
    void pop_front() {
        if (!head)
            return;

        Node* temp = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    void pop_back() {
        if (!tail) {
            return;
        }

        Node* temp = tail;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    void delete_pos(int position) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < position; i++) {
            if (!temp) {
                cout << "Position exceeds list size." << endl;
                return;
            }

            temp = temp->next;
        }

        if (!temp) {
            cout << "Position exceeds list size." << endl;
            return;
        }

        // unlink same idea and code from delete_node() in 210-dll-demo-2.cpp 

        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev;
        }

        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);


    cout << "list forward: ";
    list.print();
    cout << endl;

    cout << "list backward: ";
    list.print_reverse();
    cout << endl;

    cout << "Deleting middle value 3:" << endl;
    list.delete_val(3);
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Deleting head value 1:" << endl;
    list.delete_val(1);
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Trying to delete value 999:" << endl;
    list.delete_val(999);
    list.print();
    list.print_reverse();


    cout << endl;
    cout << "Deleting position 0:" << endl;
    list.delete_pos(0);
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Deleting last position 4:" << endl;
    list.delete_pos(4);
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Deleting middle position 1:" << endl;
    list.delete_pos(1);
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Trying to delete position 99:" << endl;
    list.delete_pos(99);
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Pop front:" << endl;
    list.pop_front();
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Pop back:" << endl;
    list.pop_back();
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Pop front again:" << endl;    
    list.pop_front();
    list.print();
    list.print_reverse();

    cout << endl;
    cout << "Pop front on empty list:" << endl;
    list.pop_front();

    cout << "Pop back on empty list:" << endl;
    list.pop_back();

    cout << endl;
    cout << "Final forward: ";
    list.print();

    cout << endl;
    cout << "Final backward: ";
    list.print_reverse();
    cout << endl;



    return 0;
}