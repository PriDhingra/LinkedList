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
    }
};

void insertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void sortLinkedList(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;

    while(curr -> next != NULL) {
        Node* temp = curr -> next;
        int smallestData = curr -> data;
        Node* smallestElement = curr;

        while(temp != NULL) {
            
            if(temp -> data < smallestData) {
                smallestData = temp -> data;
                smallestElement = temp;
                temp = temp -> next;
            } else {
                temp = temp -> next;
            }
        }
        int dataToSwap = curr -> data;
        curr -> data = smallestData;
        smallestElement -> data = dataToSwap;
        curr = curr -> next;
    }
}

void removeDuplicatesFromSortedList(Node* &head) {
    if(head == NULL)
        return;

    Node* curr = head;
    Node* prev = NULL;
    Node* nodeToDelete;

    while(curr -> next != NULL) {
        if(curr -> data != curr -> next -> data) {
            prev = curr;
            curr = curr -> next;
        } else {
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

    insertAtBeginning(head, 2);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 4);

    printLinkedList(head);
    sortLinkedList(head);
    cout<<"After Sorting Linked List\n";
    printLinkedList(head);
    removeDuplicatesFromSortedList(head);
    cout<<"After removing duplicates\n";
    printLinkedList(head);

    return 0;
}
