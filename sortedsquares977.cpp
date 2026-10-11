#include<iostream>
#include<vector>
using namespace std;
class solution {
    public:
vector<int> sortedSquares(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    vector<int>result(nums.size());
    int pos=nums.size();
    while(left<=right) {
        if(nums[left]*nums[left]>nums[right]*nums[right]){
            result[pos-1]=nums[left]*nums[left];
            left++;
            pos--;
        }
        else {
             result[pos-1]=nums[right]*nums[right];
             right--;
             pos--;
        }
    }
    cout<<"final vector of sqaures\n";
    for(int i=0;i<result.size();i++) {
        cout<<result[i]<<" ";
    }
    return result;
}
};
int main(){
    solution obj;
    vector<int>num={-4,-1,0,3,10};
    obj.sortedSquares(num);
    return 0;
}