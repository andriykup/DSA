#include<iostream>

class TreeNode{
    public:
        int value;
        TreeNode *left;
        TreeNode *right;
    
        TreeNode(){
            this->value = 0;
            this->left = NULL;
            this->right = NULL;
        }
        TreeNode(int v){
            this->value = v;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{
    public:
        TreeNode *root;

        bool isEmpty(){
            if(root == NULL){
                return true;
            } else {
                return false;
            }
        }
};

int main(){
    int option;
    
    do{
        std::cout << "What operation do you want to perform?:" << std::endl;
        std::cout << "Select option number" << std::endl;
        std::cout << "1. Insert Node" << std::endl;
        std::cout << "2. Search Node" << std::endl;
        std::cout << "3. Delete Node" << std::endl;
        std::cout << "4. Print BST values" << std::endl;
        std::cout << "5. Clear screen" << std::endl;
        std::cout << "0. Exit program" << std::endl;

        std::cin >> option;

        switch(option){
            case 0:
                break;
            case 1:
                std::cout << "Insert" << std::endl;
                //insert code
                break;
            case 2:
                std::cout << "Search" << std::endl;
                //search code
                break;
            case 3:
                std::cout << "delete" << std::endl;
                //delete code
                break;
            case 4:
                std::cout << "Print BST" << std::endl;
                //Print BST code
                break;
            case 5:
                system("clear");
                break;
            default:
                std::cout << "Enter proper option number" << std::endl;
        }
    }while(option != 0);
}