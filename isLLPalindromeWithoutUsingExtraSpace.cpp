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

Node* reverseSecondHalfOfLL(Node* &head, Node* &slow, int count) {
    Node* temp = head;

    while(temp -> next != slow) 
        temp = temp -> next;

    Node* prev = NULL;
    Node* curr = slow;
    Node* forward = NULL;
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    temp -> next = prev;
    printLinkedList(head);
    return prev;
}

bool isLLPalindrome(Node* &head) {
    Node* slow = head;
    Node* fast = head;
    Node* temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }

    while(fast -> next != NULL) {
        fast = fast -> next;
        if(fast -> next != NULL)
            fast = fast -> next;

        slow = slow -> next;
    }

    if(count % 2 != 0)
        slow = slow -> next;

    slow = reverseSecondHalfOfLL(head, slow, count);

    temp = head;
    Node* curr = slow;
    if(count % 2 == 0) {
        while(temp != slow) {
            if(temp -> data != curr -> data) 
                return false;
            else {
                temp = temp -> next;
                curr = curr -> next;
            }
        }
    } else {
        while(temp -> next != slow) {
            if(temp -> data != curr -> data) 
                return false;
            else {
                temp = temp -> next;
                curr = curr -> next;
            }
        }
    }

    return true;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    printLinkedList(head);
    
    bool result = isLLPalindrome(head);

    if(result)
        cout<<"LL is plaindrome";
    else    
        cout<<"LL is not palindrome";

    return 0;
}
