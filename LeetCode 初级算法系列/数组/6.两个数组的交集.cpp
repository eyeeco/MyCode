class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;
        vector<int> res;
        for(int i=0;i<nums2.size();i++){
            hash[nums2[i]]++;
        }
        for(int i=0;i<nums1.size();i++){
            if(hash[nums1[i]]){
                hash[nums1[i]]--;
                res.push_back(nums1[i]);
            }
        }
        return res;
    }
};
