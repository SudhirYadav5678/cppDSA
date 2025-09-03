#include<iostream>
#include<vector>
using namespace std;

void printSubSet(vector<int>&arr,vector<int>&ans,int i){
    if(i==arr.size()){
        for(int n:ans){
            cout<<n<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    printSubSet(arr,ans,i+1);
    ans.pop_back();
    printSubSet(arr,ans,i+1);
}
int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans;
    printSubSet(arr,ans,0);
    return 0;
}