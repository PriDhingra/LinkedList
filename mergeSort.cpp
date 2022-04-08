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

Node* middleNode(Node* &head) {
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

void printLinkedList(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* merge(Node* frontLL, Node* backLL) {
    Node* temp1 = frontLL;
    Node* temp2 = backLL;
    Node* result = new Node(-1);
    Node* temp = result;
    Node* forward = NULL;

    if(temp1 == NULL)
        return temp2;

    if(temp2 == NULL)
        return temp1;

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> data < temp2 -> data) {
            temp -> next = temp1;
            temp = temp1;
            temp1 = temp1 -> next;
        } else {
            temp -> next = temp2;
            temp = temp2;
            temp2 = temp2 -> next;
        }
    }

    while(temp1 != NULL) {
        temp -> next = temp1;
        temp = temp1;
        temp1 = temp1 -> next;
    }

    while(temp2 != NULL) {
        temp -> next = temp2;
        temp = temp2;
        temp2 = temp2 -> next;
    }

    result = result -> next;
    return result;
}

Node* mergeSort(Node* &head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* middle = middleNode(head);

    Node* frontLL = head;
    Node* backLL = middle -> next;
    middle -> next = NULL;

    frontLL = mergeSort(frontLL);
    backLL = mergeSort(backLL);
    Node* result = merge(frontLL, backLL);

    return result;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 5);
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 9);
    

    printLinkedList(head);
    Node* result = mergeSort(head);
    printLinkedList(result);

    return 0;
}
