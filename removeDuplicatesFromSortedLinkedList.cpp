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

void removeDuplicatesFromSortedList(Node* head) {
    Node* curr = head;
    Node* nodeToDelete;

    while(curr != NULL) {
        if(curr -> next != NULL) {
            if(curr -> data != curr -> next -> data && curr -> next != NULL) {
                curr = curr -> next;
            }
            else {
                nodeToDelete = curr -> next;
                curr -> next = curr -> next -> next;
                delete nodeToDelete;
            }
        } else {
            curr = curr -> next;
        }
    }
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

    insertAtBeginning(head, 8);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    printLinkedList(head);
    removeDuplicatesFromSortedList(head);
    printLinkedList(head);

    return 0;
}
