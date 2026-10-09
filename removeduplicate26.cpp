#include<iostream>
#include<vector>
using namespace std;
    class Solution {
public:
    int index=1;
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=nums[i-1]) {
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};
int main() {
    Solution s;
    vector<int>num={1,1,2,3,4,4,5,6};
    int newlength=s.removeDuplicates(num);
    cout<<"new size is"<<newlength;
    return 0;
    
}