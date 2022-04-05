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

void printLinkedList(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void reverseLL(Node* &head) {

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
}

Node* sumOfTwoLL(Node* &head1, Node* &head2) {
    reverseLL(head1);
    reverseLL(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;
    
    int carry = 0;

    Node* result = NULL;
    int sum = 0;
    while(temp1 != NULL || temp2 != NULL || carry != 0) {

        int val1 = 0;
        if(temp1 != NULL)
            val1 = temp1 -> data;

        int val2 = 0;
        if(temp2 != NULL) 
            val2 = temp2 -> data;

        sum = val1 + val2 + carry;

        insertAtBeginning(result, sum % 10);
        carry = sum / 10;

        if(temp1 != NULL) 
            temp1 = temp1 -> next;
        
        if(temp2 != NULL)
            temp2 = temp2 -> next;
    }

    return result;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertAtBeginning(head1, 5);
    insertAtBeginning(head1, 7);
    insertAtBeginning(head1, 6);
    insertAtBeginning(head1, 6);

    insertAtBeginning(head2, 8);
    insertAtBeginning(head2, 9);
    insertAtBeginning(head2, 7);
    insertAtBeginning(head2, 9);
    insertAtBeginning(head2, 7);

    printLinkedList(head1);
    printLinkedList(head2);
    
    Node* result = sumOfTwoLL(head1, head2);
    cout<<"Sum of 2 Linked List : ";
    printLinkedList(result);

    return 0;
}
