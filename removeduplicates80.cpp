#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); 
        int index=2;
        for(int i=2;i<nums.size();i++) {
            if(nums[i]!=nums[index-2]) {
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};
int main() {
    Solution obj;
    vector<int>vec={1,1,1,2,2,3};
    int result=obj.removeDuplicates(vec);
    cout<<"new size of array :"<<" "<<result<<endl;
    for(int i=0;i<result;i++){
        cout<<vec[i]<<endl;
    }
}