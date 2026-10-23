#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int maxarea(vector<int>& height){
        int left=0;
        int right=height.size()-1;
        int maxarea=0;
        while(left<right) {
            int currentheight=min(height[left],height[right]);
            int currentwidth=right-left;
            int currentarea=currentheight*currentwidth;
            maxarea=max(currentarea,maxarea);
            if(height[left]<height[right]){
                left++;
            }
            else {
                right--;
            }
        }
        return maxarea;
    }
};
int main() {
    Solution obj;
    vector<int>vec={1,8,2,5,6,3,7};
    int result=obj.maxarea(vec);
    cout<<"maximum area is"<<" "<<result;
    return 0;
}