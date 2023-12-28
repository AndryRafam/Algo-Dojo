/*Time Complexity: O(logN); where N is the size of the array.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    static int peakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r) {
            int m = (l+r) >> 1;
            if(nums[m]>=nums[m+1]) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << Solution::peakElement(nums);
    return 0;
}
