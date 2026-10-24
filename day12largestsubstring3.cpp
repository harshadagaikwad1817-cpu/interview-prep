#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    // The Setup: Checklist, back bouncer, and record book
    /*the seen(256,false) makes 256 boxes having ascii values and makes them false so when we 
    put an value like a it gets true and we get know if there is already another a existing in 
    substring*/
    vector<bool> seen(256, false); 
    int left = 0; 
    int max_length = 0; 
    
    // The front bouncer walks down the string
    for (int right = 0; right < s.length(); right++) {
        
        // RULE 1: The Alarm Check
        while (seen[s[right]] == true) {
            seen[s[left]] = false; // Erase checkmark
            left++; // Move back door forward
        }
        
        // RULE 2: Enter the Club
        seen[s[right]] = true; // Draw the checkmark
        // RULE 3: Count the Crowd
        int currentlength = right - left + 1;
        max_length = max(max_length, currentlength);
    }
    
    return max_length;
}

int main() {
    string test_str = "aba";
    cout << "Longest unique substring length: " << lengthOfLongestSubstring(test_str) << endl;
    return 0;
}