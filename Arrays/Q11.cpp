// 287. Find the Duplicate Number
// link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        
        fast = nums[0];
        while(slow!=fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
