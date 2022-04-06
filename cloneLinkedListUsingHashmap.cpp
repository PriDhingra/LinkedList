#include<iostream>
#include<map>

using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node* random;

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

void reverseLinkedList(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
}

void printLinkedList(Node* &head) {
    Node* temp = head;
    cout<<"Node -> data          Node -> random -> data"<<endl; 
    while(temp != NULL) {
        cout<<"     "<<temp -> data<<"                         "<<temp -> random -> data<<endl;
        temp = temp -> next;
    }
}

Node* cloneNode(Node* &head) {
    Node* cloneNode = NULL;
    Node* temp = head;

    while(temp != NULL) {
        insertAtBeginning(cloneNode, temp -> data);
        temp = temp -> next;
    }

    reverseLinkedList(cloneNode);

    map<Node*, Node*> randomMapping;

    temp = head;
    Node* cloneTemp = cloneNode;
    while(temp != NULL) {
        randomMapping[temp] = cloneTemp;
        temp = temp -> next;
        cloneTemp = cloneTemp -> next;
    }

    temp = head;
    cloneTemp = cloneNode;
    while(temp != NULL) {
        cloneTemp -> random = randomMapping[temp -> random];
        temp = temp -> next;
        cloneTemp = cloneTemp -> next;
    }

    return cloneNode;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 5);
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 9);

    Node* temp = head;
    temp -> random = head -> next -> next -> next;
    temp = temp -> next;
    temp -> random = head -> next -> next -> next -> next;
    temp = temp -> next;
    temp -> random = head;
    temp = temp -> next;
    temp -> random = head -> next -> next;
    temp = temp -> next;
    temp -> random = head -> next;

    
    printLinkedList(head);
    
    Node* cloneNodeResult = cloneNode(head);

    printLinkedList(cloneNodeResult);

    return 0;
}
