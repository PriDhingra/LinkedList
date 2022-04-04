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

void sort0s1s2sUsingCount(Node* &head) {
    Node* temp = head;
    
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    while(temp != NULL) {
        if(temp -> data == 0)
            zeroCount++;
        else if(temp -> data == 1)
            oneCount++;
        else if(temp -> data == 2)
            twoCount++;

        temp = temp -> next;
    }

    temp = head;

    while(zeroCount > 0) {
        temp -> data = 0;
        temp = temp -> next;
        zeroCount--;
    }

    while(oneCount > 0) {
        temp -> data = 1;
        temp = temp -> next;
        oneCount--;
    }

    while(twoCount > 0) {
        temp -> data = 2;
        temp = temp -> next;
        twoCount--;
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
    sort0s1s2sUsingCount(head);
    printLinkedList(head);

    return 0;
}
