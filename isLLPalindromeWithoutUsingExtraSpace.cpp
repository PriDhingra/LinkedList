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

Node* reverseSecondHalfOfLL(Node* &head) {

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;

}

Node* middleEl(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast -> next != NULL) {
        fast = fast -> next;
        if(fast -> next != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;

    }

    return slow;
}

bool isLLPalindrome(Node* &head) {
    if(head == NULL || head -> next == NULL) {
        return true;
    }

    Node* middle = middleEl(head);

    Node* temp = middle -> next;
    middle -> next = reverseSecondHalfOfLL(temp);

    Node* head1 = head;
    Node* head2 = middle -> next;
    
    while(head2 != NULL) {
        if(head1 -> data != head2 -> data)
            return false;
    
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    temp = middle -> next;
    middle -> next = reverseSecondHalfOfLL(temp);

    return true;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
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
