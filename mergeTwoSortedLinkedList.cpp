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

void solve(Node* &head1, Node* &head2) {
    Node* prev = head1;
    Node* curr = head1 -> next;

    Node* temp = head2;
    Node* forward = NULL;

    while(temp != NULL && curr != NULL) {
        // cout<<prev -> data<<temp -> data<<curr->data<<endl;
        if(prev -> data <= temp -> data && temp -> data <= curr -> data) {
            // cout<<prev -> data<<temp -> data<<curr->data<<endl;
            forward = temp -> next;
            temp -> next = curr;
            prev -> next = temp;
            prev = prev -> next;
            temp = forward;
        } else {
            prev = curr;
            curr = curr -> next;
        }
    }
    while(prev -> next != NULL)
        prev = prev -> next;
        
    prev -> next = temp;
}

Node* mergeTwoSortedLinkedList(Node* &head1, Node* &head2) {
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1; 

    if(head1 -> data <= head2 -> data) {
        solve(head1, head2);
        return head1;
    } else {
        solve(head2, head1);
        return head2;
    }
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertAtBeginning(head1, 5);
    insertAtBeginning(head1, 4);
    insertAtBeginning(head1, 1);
    // insertAtBeginning(head1, 2);
    // insertAtBeginning(head1, 1);

    insertAtBeginning(head2, 5);
    insertAtBeginning(head2, 3);
    insertAtBeginning(head2, 2);
    // insertAtBeginning(head2, 1);
    

    printLinkedList(head1);
    printLinkedList(head2);
    
    Node* result = mergeTwoSortedLinkedList(head1, head2);
    printLinkedList(head1);

    return 0;
}
