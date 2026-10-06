#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>& vec,int target) {
    for(int val:vec) {
        if (val==target) {
            cout<<"found";
            break;
        }
    
    }
    return 0;
}
int main() {
    vector<int>vec1={1,2,3,4};
    find(vec1,2);
    return 0;

}