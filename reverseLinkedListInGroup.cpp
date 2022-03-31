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


Node* reverseLinkedListInGroup(Node* &head, int k) {
    
    if(head == NULL) 
        return NULL;

    int count = 0;
    Node* prev = NULL;
    Node* forward = NULL;
    Node* curr = head;
    
    while(count < k && curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL)
        head -> next = reverseLinkedListInGroup(curr, k);

    return prev;
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
    insertAtEnd(head, 16);
    insertAtPosition(head, 18, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 24, 4);
    insertAtPosition(head, 26, 4);

    printLinkedList(head);

    Node* result = reverseLinkedListInGroup(head, 2);

    printLinkedList(result);

    return 0;
}
