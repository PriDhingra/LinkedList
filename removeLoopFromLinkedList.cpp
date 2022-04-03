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
    };

};

void insertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;

    while(temp -> next != NULL) 
        temp = temp -> next;

    temp -> next = newNode;
    
}

void insertAtPosition(Node* &head, int data, int pos) {
    Node* newNode = new Node(data);
    Node* temp = head;

    if(pos == 1) {
        insertAtBeginning(head, data);
        return;
    }

    while(pos - 1 > 1) {
        temp = temp -> next;
        pos--;
    }

    if(temp -> next == NULL) {
        insertAtEnd(head, data);
        return;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
}

Node* floydDetectLoop(Node* &head) {
    if(head == NULL) 
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        fast = fast -> next;
        if(fast != NULL)
            fast = fast -> next;

        slow = slow -> next;

        if(slow == fast) {
            cout<<"Cycle present at "<<slow -> data<<"\n";
            return slow;
        }
    }

    return NULL;
}

Node* startNodeOfLoop(Node* &head) {
    if(head == NULL) 
        return NULL;

    Node* slow = head;
    Node* fast = head;

    bool temp = false;;

    while(slow != NULL && fast != NULL && !temp) {
        fast = fast -> next;
        if(fast != NULL)
            fast = fast -> next;

        slow = slow -> next;

        if(slow == fast) {
            temp = true;
            slow = head;
        }
    }

    while(slow != fast) { 
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

void removeLoop(Node* head) {
    if(head == NULL) 
        return;

    Node* startLoop = startNodeOfLoop(head);

    Node* temp = head;

    while(temp -> next != startLoop) {
        temp = temp -> next;
    }

    temp -> next = NULL;
}

void insertLoopInLinkedList(Node* &head) {
    Node* temp = head;

    while(temp -> next != NULL) 
        temp = temp -> next;

    temp -> next = head -> next -> next;
}

int main() {
    Node* head = NULL;

    insertAtBeginning(head, 2);
    insertAtBeginning(head, 4);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 10);
    insertAtEnd(head, 12);
    insertAtEnd(head, 14);
    insertAtEnd(head, 16);
    insertAtPosition(head, 90, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 24, 4);
    insertAtPosition(head, 26, 4);
    insertAtPosition(head, 18, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 24, 4);
    insertAtPosition(head, 26, 4);

    insertLoopInLinkedList(head);

    Node* startPoint = startNodeOfLoop(head);

    Node* result = floydDetectLoop(head);
    if(result != NULL) 
        cout<<"Loop is present\n";
    else    
        cout<<"Loop is not present\n";

    cout<<"Start Point of Loop is "<<startPoint -> data<<"\n";

    removeLoop(head);

    result = floydDetectLoop(head);
        if(result != NULL) 
            cout<<"Loop is present\n";
        else    
            cout<<"Loop is not present\n";

    return 0;
}
