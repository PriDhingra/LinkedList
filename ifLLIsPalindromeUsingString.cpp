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

string reverseString(string str) {
    for(int i = 0; i< str.length() / 2;i++) {
        swap(str[i], str[str.length() - i - 1]);
    }

    return str;
}

bool isLLPalindrome(Node* &head) {
    string str = "";
    Node* temp = head;

    while(temp != NULL) {
        str = str + to_string(temp -> data);
        temp = temp -> next;
    }
    
    if(str == reverseString(str))
        return true;
    else 
        return false;

}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
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
