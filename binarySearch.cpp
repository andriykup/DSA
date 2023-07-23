#include<iostream>

int arrLen(int arr[]){
    int i = 0;
    while(arr[i]){
        i++;
    }
    return i - 1;
}

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

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,11,12,13,14,15,21,24,29,30,45,46,48,49,50};
    int key = 29;

    int position = binarySearch(arr, key);
    if(position == -1){
        std::cout << "key not found" << std::endl;
    }else{
    std::cout << "Binary Search: (iterative method)" << std::endl;
    std::cout << position << " is the position of " << key << " in array" << std::endl;
    }

    return 0;
}