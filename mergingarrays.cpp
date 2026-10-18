#include <iostream>
using namespace std;
void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;         // Pointer for the last real number in nums1
    int j = n - 1;         // Pointer for the last number in nums2
    int k = m + n - 1;     // Pointer for the very end of nums1's total capacity

    // Compare from the back and put the largest number at the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are any numbers left in nums2, copy them over
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    // nums1 has a total size of 6, but only 3 real numbers (m = 3)
    int nums1[6] = {1, 2, 3, 0, 0, 0}; 
    int nums2[3] = {2, 5, 6};
    
    merge(nums1, 3, nums2, 3);
    
    cout << "Merged Array: ";
    for (int i = 0; i < 6; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    
    return 0;
}