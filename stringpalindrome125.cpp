#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int left=0;
    bool isPalindrome(string s) {
    int right=s.length();
    while(left<right) {
        if(!isalnum(s[left])) {
            left++;
        }
        else if(!isalnum(s[right])){
            right--;
        }
        else {
            if(tolower(s[left])!=tolower(s[right])) {
            return false;
        }
        left++;
        right--;
        }
    }
    return true;
    }
};
int main() {
    Solution obj;
    string sub="hii i iih";
    int result=obj.isPalindrome(sub);
    if(result==true) {
        cout<<"string is palindrome\n";
    }
    else {
        cout<<"string is not an palindrome";
    }
    return 0;
}