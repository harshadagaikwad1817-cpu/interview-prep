#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum=0;
        
            for(int i=0;i<k;i++){
                current_sum+=nums[i];

            }
            double max_sum=current_sum;
            for(int i=k;i<nums.size();i++) {
                current_sum=current_sum-nums[i-k]+nums[i];
                max_sum=max(current_sum,max_sum);
            }
    return max_sum/k;
    }
};
int main() {
    Solution obj;
    vector<int>vec={1,12,-5,-6,50,3};
    cout<<"Maximum average is"<<obj.findMaxAverage(vec,4)<<endl;
    return 0;
}