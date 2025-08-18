#include<iostream>
#include<vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    cout<<"Heloo";
    int l=nums.size()-2,r=nums.size()-1;
    while(l<r){
        if(nums[l]<nums[r]){
        int temp = nums[r];
        nums[r]=nums[l];
        nums[l]=temp;
        }
        else if(nums[l]>nums[r]){
        if(l==0){
            int temp = nums[0];
            nums[0]=nums[r];
            nums[r]=nums[0];
            }
            l--;
            r--;
           }
        }
}
void name(){

}
int main(){
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}