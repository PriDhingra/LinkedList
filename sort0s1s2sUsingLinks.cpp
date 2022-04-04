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

void insertAtTail(Node* &tail, Node* &curr) {
    tail -> next = curr;
    tail = curr;
}

void sort0s1s2sUsingLinks(Node* &head) {
    if(head == NULL)
        return;
    
    Node* curr = head;

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    while(curr != NULL) {
        if(curr -> data == 0) {
            insertAtTail(zeroTail, curr);
        } else if(curr -> data == 1) {
            insertAtTail(oneTail, curr);
        } else if(curr -> data == 2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    if(oneHead -> next != NULL)
        zeroTail -> next = oneHead -> next;
    else 
        zeroTail -> next = twoHead -> next;

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL; 

    head = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
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
    insertAtBeginning(head, 0);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 0);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 0);
    insertAtBeginning(head, 1);

    printLinkedList(head);
    sort0s1s2sUsingLinks(head);
    printLinkedList(head);

    return 0;
}
