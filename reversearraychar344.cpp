#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int left=0;
    
    void reverseString(vector<char>& s) {
    int right=s.size()-1;
    while(left<right) {
        swap(s[left],s[right]);
        left++;
        right--;

    }
    cout<<"reversed array is: "<<endl;
    for(int i=0;i<s.size();i++){
        
        cout<<s[i]<<" ";
    }
    
    }
};
int main() {
    Solution obj;
    vector<char>vec={'h','a','r','s','h','a','d','a'};
    obj.reverseString(vec);   
}