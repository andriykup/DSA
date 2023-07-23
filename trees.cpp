#include<iostream>

class Node{
    public:
        int value;
        Node *left;
        Node *right;
};

Node *createNode(int data){
    Node *newNode = new Node();
    newNode->value = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;    
}

int main(){
    Node *root = createNode(1);

    return 0;
}