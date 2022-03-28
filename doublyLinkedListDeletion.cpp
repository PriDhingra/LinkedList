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

    ~Node() {
        int value = this -> data;
        if(next != NULL) {
            next = NULL;
            delete next;
        }
        cout<<"memory free for "<<value<<endl;
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

void deleteAtBeginning(Node* &head) {
    Node* temp = head;
    head = head -> next;
    head -> prev = NULL;

    delete temp;
}

void deleteAtEnd(Node* head) {
    Node* temp = head;

    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next -> prev = NULL;
    delete temp -> next;
    temp -> next = NULL;
}

void deleteAtPosition(Node* &head, int pos) {
    Node* temp = head;

    if(pos == 1) {
        deleteAtBeginning(head);
        return;
    }

    while(pos - 1 > 1) {
        temp = temp -> next;
        pos--;
    }

    if(temp -> next -> next == NULL) {
        deleteAtEnd(head);
        return;
    }

    Node* temp1 = temp -> next;
    temp -> next -> next -> prev = temp;
    temp -> next = temp -> next -> next; 

    temp1 -> next = NULL;
    temp1 -> prev = NULL;
    delete temp1;
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
    insertAtPosition(head, 22, 12);
    deleteAtBeginning(head);
    deleteAtBeginning(head);
    deleteAtBeginning(head);
    deleteAtEnd(head);
    deleteAtEnd(head);
    deleteAtPosition(head, 2);
    deleteAtPosition(head, 1);
    deleteAtPosition(head, 5);

    printLinkedList(head);

    return 0;
}
