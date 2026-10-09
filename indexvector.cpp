#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int index=0;
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=val) {
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};
int main() {
    Solution obj;
    vector<int>nums={1,2,3,3,4,5,3};
    int val=3;
    int newlength=obj.removeElement(nums,val);
    cout<<"new size of vector is\n"<<newlength<<endl; //                                                                                                        length<<endl;
    for(int i=0;i<newlength;i++) {
        cout<<nums[i]<<endl;
    }
    return 0;
}