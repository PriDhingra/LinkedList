#include<iostream>

using namespace std;

class Node {
    public: 
        int data;
        Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    };

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

Node* middleElement(Node* &head) {
    Node* temp1 = head;
    Node* temp2 = head;

    while(temp2 -> next != NULL) {
        temp1 = temp1 -> next;

        if(temp2 -> next -> next != NULL)
            temp2 = temp2 -> next -> next;
        else
            temp2 = temp2 -> next;
    }

    return temp1;
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
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 10);
    insertAtEnd(head, 12);
    insertAtEnd(head, 14);
    insertAtPosition(head, 18, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 24, 4);
    insertAtPosition(head, 26, 4);

    printLinkedList(head);

    Node* middleNode = middleElement(head);
    cout<<"Middle Element of Linked List is "<<middleNode -> data;

    return 0;
}
