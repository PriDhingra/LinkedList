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

void removeDuplicatesFromSortedList(Node* head) {
    if(head == NULL)
        return;

    Node* curr = head;
    Node* nodeToDelete;

    while(curr -> next != NULL) {
        if(curr -> data != curr -> next -> data) {
            curr = curr -> next;
        }
        else {
            nodeToDelete = curr -> next;
            curr -> next = curr -> next -> next;
            delete nodeToDelete;
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
