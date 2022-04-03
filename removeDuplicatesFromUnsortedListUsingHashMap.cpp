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

void removeDuplicatesFromUnsortedList(Node* head) {
    if(head == NULL)
        return;

    Node* curr = head;
    Node* prev = NULL;
    Node* nodeToDelete;
    map<int, bool> visited;

    while(curr != NULL) {
        if(visited[curr -> data] == true) {
            nodeToDelete = curr;
            prev -> next = curr -> next;
            curr = curr -> next;
            delete nodeToDelete;
        } else {
            visited[curr -> data] = true;
            prev = curr;
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
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 4);

    printLinkedList(head);
    removeDuplicatesFromUnsortedList(head);
    cout<<"After removing Duplicates\n";
    printLinkedList(head);

    return 0;
}
