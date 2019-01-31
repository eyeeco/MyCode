class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return *it==target?it-nums.begin():-1;
    }
};
