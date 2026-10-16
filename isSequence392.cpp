#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.length() && j<t.length()) {
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else {
                j++;
            }
        }
         if(i==s.length()){
            return true;
         }
         else{
            return false;
         }
    }
};
int main() {
    Solution obj;
    string str1="abc";
    string str2="axbfghc";
    bool result=obj.isSubsequence(str1,str2);
    cout<<result;
    return 0;
}