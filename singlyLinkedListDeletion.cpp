#include<iostream>

using namespace std;

class Node {
    public: 
        int data;
        Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;

    while(temp -> next != NULL) 
        temp = temp -> next;

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

    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void deleteAtBeginning(Node* &head) {
    Node* temp = head;
    head = head -> next;

    delete temp;
}

void deleteAtEnd(Node* &head) {
    Node* temp = head;

    while(temp -> next -> next != NULL) 
        temp = temp -> next;

    delete temp -> next;
    temp -> next = NULL;
}

void deleteAtPosition(Node* &head, int pos) {
    if(pos == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = head;

    while(pos - 1 > 1) {
        temp = temp -> next;
        pos--;
    }

    if(temp -> next -> next == NULL) {
        deleteAtEnd(head);
        return;
    }

    Node* temp1 = temp -> next -> next;
    delete temp -> next;
    temp -> next = temp1;
}

void printLinkedList(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 2);
    printLinkedList(head);
    insertAtBeginning(head, 4);
    printLinkedList(head);
    insertAtBeginning(head, 6);
    printLinkedList(head);
    insertAtBeginning(head, 8);
    printLinkedList(head);
    insertAtBeginning(head, 10);
    printLinkedList(head);
    insertAtEnd(head, 12);
    printLinkedList(head);
    insertAtEnd(head, 14);
    printLinkedList(head);
    insertAtEnd(head, 16);
    printLinkedList(head);
    insertAtPosition(head, 18, 1);
    printLinkedList(head);
    insertAtPosition(head, 20, 2);
    printLinkedList(head);
    insertAtPosition(head, 24, 4);
    printLinkedList(head);
    insertAtPosition(head, 24, 12);
    printLinkedList(head);
    deleteAtBeginning(head);
    printLinkedList(head);
    deleteAtBeginning(head);
    printLinkedList(head);
    deleteAtEnd(head);
    printLinkedList(head);
    deleteAtEnd(head);
    printLinkedList(head);
    deleteAtEnd(head);
    printLinkedList(head);
    deleteAtPosition(head, 1);
    printLinkedList(head);
    deleteAtPosition(head, 4);
    printLinkedList(head);
    deleteAtPosition(head, 5);
    printLinkedList(head);


    return 0;
}
