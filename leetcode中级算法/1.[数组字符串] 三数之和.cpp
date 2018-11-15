class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]==-nums[i]){
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    res.insert(temp);
                    left++;
                }else if(nums[left]+nums[right]<-nums[i]){
                    left++;
                }else
                    right--;
            }
        }
        vector<vector<int>> os(res.begin(),res.end());
        return os;
    }
};
