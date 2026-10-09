#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int index=0;
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]^nums^[i]!=0) {
                nums[index]=nums[i];
            }
        }
        return index;
    }
};
int main() {
    Solution s;
    vector<int>& nums={1,1,2,3,4,4,5,6};
    int newlength=s.removeDuplicates(nums);
    cout<<"new size is"<<newlength;
    return 0;
    
}