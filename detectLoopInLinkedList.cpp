#include<iostream>
#include<map>

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


bool isLoopDetected(Node* &head) {
    if(head == NULL) 
        return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true)
            return true;
        
        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}

void insertLoopInLinkedList(Node* &head) {
    Node* temp = head;

    while(temp -> next != NULL) 
        temp = temp -> next;

    temp -> next = head -> next -> next;
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
    insertAtPosition(head, 18, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 24, 4);
    insertAtPosition(head, 26, 4);

    insertLoopInLinkedList(head);

    if(isLoopDetected(head)) 
        cout<<"Loop detected in linked list";
    else
        cout<<"Loop not detected";

    return 0;
}
