#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==0) {
           cout<<"vec remains as it is";
        }
        int lit=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) {
                nums[lit]=nums[i];
                lit++;
            }
        }
        while (lit< nums.size()) {
            nums[lit] = 0;
            lit++;
        }
    }
};
int main() {
    Solution obj;
    vector<int>vec={0,2,0,4,5,6,0};
    obj.moveZeroes(vec);
    cout<<"new vector"<<endl;
    for(int i=0;i<vec.size();i++) {
        cout<<vec[i]<<"  ";
    }
    return 0;
}