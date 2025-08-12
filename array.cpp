#include<iostream>
using namespace std;

int main(){
    int arr[5]= {1,3,4,5,6};
    //size of array.
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<length;
    return 0;
}