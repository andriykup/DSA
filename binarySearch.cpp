#include<iostream>

int arrLen(int arr[]){
    int i = 0;
    while(arr[i]){
        i++;
    }
    return i - 1;
}

// complexity: O(logn)
int binarySearch(int arr[], int key){
    int l = 0;
    int h = arrLen(arr);
    int m;

    while(l <= h){
        m = (l + h) / 2;
        if(arr[m] == key){
            return m;
        }else if(key < arr[m]){
            h = m - 1;
        }else{
            l = m + 1;
        }
    }

    return -1;
}

int binarySearchR(int arr[], int key, int l, int h){ //Recursive Method
    int m;
    if(l == h){
        if(arr[l] == key){
            return l;
        }else{
            return -1;
        }
    }else{
        m = (l + h) / 2;
        if(key == arr[m]){
            return m;
        }
        if(key < arr[m]){
            return binarySearchR(arr, key, l, m - 1);
        }else{
            return binarySearchR(arr, key, m + 1, h);
        }
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,11,12,13,14,15,21,24,29,30,45,46,48,49,50};
    //int arr[] = {1}; //----> test with only one element in the array
    int key = 29;

    //iterative
    int position = binarySearch(arr, key);
    if(position == -1){
        std::cout << "key not found" << std::endl;
    }else{
    std::cout << "Binary Search: (iterative method)" << std::endl;
    std::cout << position << " is the position of " << key << " in array" << std::endl;
    }

    //recursive
    int l = 0;
    int h = arrLen(arr);
    int positionR = binarySearchR(arr, key, l, h);
    if(positionR == -1){
        std::cout << "key not found" << std::endl;
    }else{
    std::cout << "Binary Search: (recursive method)" << std::endl;
    std::cout << positionR << " is the position of " << key << " in array" << std::endl;
    }

    return 0;
}