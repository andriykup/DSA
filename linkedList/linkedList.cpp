#include<iostream>

class Node{
    public:
        int value;
        Node *next;
};

void printList(Node *head);

int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;

    printList(head);

    return 0;
}

void printList(Node *head){
    while(head){
        std::cout << head->value << std::endl;
        head = head->next;
    }
}

