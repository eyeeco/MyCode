class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> con;
        vector<int> res;
        for(int i=0;i<k-1;i++){
            while(!con.empty()&&nums[i]>nums[con.back()]){
                con.pop_back();
            }
            con.push_back(i);
        }
        for(int i=k-1;i<nums.size();i++){
            while(!con.empty()&&nums[i]>nums[con.back()]){
                con.pop_back();
            }
            con.push_back(i);
            res.push_back(nums[con.front()]);
            if(con.front()==i-k+1) con.pop_front();
        }
        return res;
    }
};
