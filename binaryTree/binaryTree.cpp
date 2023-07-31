#include<iostream>
#define SPACE 10

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
        BST(){
            root = NULL;
        }
        bool isEmpty(){
            if(root == NULL){
                return true;
            } else {
                return false;
            }
        }

        TreeNode *minValueNode(TreeNode *node){
            TreeNode *current = node;
            while(current->left != NULL){
                current = current->left;
            }
            return current;
        }

        int treeHeight(TreeNode *root){ //finding height of binary tree
            if(root == NULL){
                return -1;
            }else{
                int lheight = treeHeight(root->left);
                int rheight = treeHeight(root->right);
                if(lheight > rheight){
                    return lheight + 1;
                }else{
                    return rheight + 1;
                }
            }
        }

        void print2D(TreeNode *r, int space){
            if (r == NULL)
                return;
            space += SPACE;
            print2D(r->right, space);
            std::cout << std::endl;
            for (int i = SPACE; i < space; i++){
                std::cout << " ";
            } 
            std::cout << r->value << "\n";
            print2D(r->left, space);
        }

        void insertNode(TreeNode *new_node){
            if(root == NULL){
                root = new_node;
                std::cout << "Value inserted as root node." << std::endl;
            }else{
                TreeNode *temp = root;
                while(temp != NULL){
                    if(new_node->value == temp->value){
                        std::cout << "Value already exist,"
                        << "please insert another value." << std::endl;
                        return;
                    }else if((new_node->value < temp->value) && (temp->left == NULL)){
                        temp->left = new_node;
                        std::cout << "Value inserted to the left." << std::endl;
                        break;
                    }else if(new_node->value < temp->value){
                        temp = temp->left;
                    }else if((new_node->value > temp->value) && (temp->right == NULL)){
                        temp->right = new_node;
                        std::cout << "Value inserted to the right." << std::endl;
                        break;
                    }else{
                        temp = temp->right;
                    }
                }
            }
        }

        TreeNode *iterativeSearch(int value){
            if(root == NULL){
                return root;
            }else{
                TreeNode *temp = root;
                while(temp != NULL){
                    if(value == temp->value){
                        return temp;
                    }else if(value < temp->value){
                        temp = temp->left;
                    }else if(value > temp->value){
                        temp = temp->right;
                    }
                }
                return NULL;
            }
        }

        TreeNode *deleteNode(TreeNode *root, int val){
            TreeNode *temp;
            if(root == NULL){
                return root;
            }else if(val < root->value){
                root->left = deleteNode(root->left, val);
            }else if(val > root->value){
                root->right = deleteNode(root->right, val);
            }else{
                if(root->left == NULL){ //NODE with only rigth child or NO child
                    temp = root->right;
                    delete root;
                    return temp;
                }else if(root->right == NULL){ //NODE only with left child
                    temp = root->right;
                    delete root;
                    return temp;
                }else{ //node with TWO childs
                    temp = minValueNode(root->right);
                    root->value = temp->value;
                    root->right = deleteNode(root->right, temp->value);
                    return root;
                }
            }
            return root;
        }
};



int main(){
    BST obj;
    int option, val;
    
    do{
        std::cout << "What operation do you want to perform?:" << std::endl;
        std::cout << "Select option number" << std::endl;
        std::cout << "1. Insert Node" << std::endl;
        std::cout << "2. Search Node" << std::endl;
        std::cout << "3. Delete Node" << std::endl;
        std::cout << "4. Print BST values" << std::endl;
        std::cout << "5. Print height of binary tree" << std::endl;
        std::cout << "6. Clear screen" << std::endl;
        std::cout << "0. Exit program" << std::endl;

        std::cin >> option;

        //creating NODE n1
        TreeNode *new_node = new TreeNode();

        switch(option){
            case 0:
                break;
            case 1:
                std::cout << "Insert" << std::endl;
                std::cout << "Enter the VALUE of TREE NODE to INSERT in BST:";
                std::cin >> val;
                new_node->value = val;
                obj.insertNode(new_node);
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "Search" << std::endl;
                int value;
                std::cout << "Enter the VALUE:" << std::endl;
                std::cin >> value;
                if(obj.iterativeSearch(value) != NULL){
                    std::cout << "Value found" << std::endl;
                }else{
                    std::cout << "Value not found :(" << std::endl;
                }
                break;
            case 3:
                std::cout << "delete" << std::endl;
                int val;
                std::cout << "Enter the VALUE that you wish to delete: ";
                std::cin >> val;
                new_node = obj.iterativeSearch(val);
                if(new_node != NULL){
                    obj.deleteNode(obj.root, val);
                    std::cout << "Value deleted" << std::endl;
                }else{
                    std::cout << "Value NOT found" << std::endl;
                }
                break;
            case 4:
                std::cout << "Print BST" << std::endl;
                obj.print2D(obj.root, 5);
                break;
            case 5:
                // printing the height of the tree
                std::cout << "\n" << "Height of binary tree: " << 
                obj.treeHeight(obj.root) << "\n\n";
                break;
            case 6:
                system("clear");
                break;
            default:
                std::cout << "Enter proper option number" << std::endl;
        }
    }while(option != 0);
}