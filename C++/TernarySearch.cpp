// C++ program to implement recursive Ternary Search 
#include<iostream>
using namespace std;

template<class T>
int ternarySearch(T *arr, int l, int r, T key)
{
    if(r >= l)
    {
        r = r - 1;
        int mid1 = l + ((r-l)/3);
        int mid2 = r - ((r-l)/3);
        if(arr[mid1] == key)
            return mid1;
        else if(arr[mid2] == key)
            return mid2;
        else if( key < arr[mid1])
            return ternarySearch(arr, l, mid1-1, key);
        else if(key > arr[mid2])
            return ternarySearch(arr, mid2+1, r, key);
        else 
            return ternarySearch(arr, mid1+1, mid2-1, key); 
    }
    return -1;
}

int main()
{
    int index, n, x = 4;
    int arr[] = {1,2,3,4,5};
    n = sizeof(arr)/sizeof(arr[0]);
    index = ternarySearch<int>(arr, 0, n, x);
    (index == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << index; 
}