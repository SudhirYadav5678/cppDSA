#include<iostream>
using namespace std;

int recursion(int n){
    if(n==0){
        return 1;
    }
    cout<<n<<endl;
    return n*recursion(n-1);
}


int main(){
    cout<<"Hello"<<endl;
    cout<<recursion(4)<<endl;
    return 0;
}