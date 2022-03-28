#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node(data);
    
    newNode -> next = head;
    
    if(head != NULL)
        head -> prev = newNode;
    
    head = newNode;
}

void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);

    if(head == NULL) {
        insertAtBeginning(head, data);
        return;
    }

    Node* temp = head;

    while(temp -> next != NULL) 
        temp = temp -> next;

    newNode -> prev = temp;
    temp -> next = newNode;
}

void insertAtPosition(Node* &head, int data, int pos) {
    Node* newNode = new Node(data);

    Node* temp = head;

    if(pos == 1) {
        insertAtBeginning(head, data);
        return;
    }

    while(pos - 1 > 1) {
        temp = temp -> next;
        pos--;
    }

    if(temp -> next == NULL) {
        insertAtEnd(head, data);
        return;
    }

    temp -> next -> prev = newNode;
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    temp -> next = newNode;
}

void printLinkedList(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> prev<<" "<<temp -> data<<" "<<temp -> next;
        cout<<endl;
        temp = temp -> next;
    }
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 0);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 8);
    insertAtEnd(head, 10);
    insertAtEnd(head, 12);
    insertAtEnd(head, 14);
    insertAtPosition(head, 16, 3);
    insertAtPosition(head, 18, 5);
    insertAtPosition(head, 20, 1);

    printLinkedList(head);

    return 0;
}
