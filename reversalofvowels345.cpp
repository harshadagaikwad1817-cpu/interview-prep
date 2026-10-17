#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isVowel(char c) {
    c = tolower(c); // Handle uppercase vowels easily
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
    string reverseVowels(string s) {
    int left=0;
    int right=s.length()-1;
    while(left<right) {
        if(!isVowel(s[left])) {
            left++;
        }
        else if(!isVowel(s[right])) {
            right--;
        }
        else {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    return s;
    }
};
int main() {
    Solution obj;
    string str="hello i am harshu";
    cout<<obj.reverseVowels(str);
    //cout<<str2;
    return 0;
}