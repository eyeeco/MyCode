class Solution {
public:
    vector<int> ori;
    vector<int> suff;
    Solution(vector<int> nums) {
        ori = nums ;
        suff = nums;
    }
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        suff = ori;
        return suff;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=0;i<suff.size();i++){
            int k = rand()%(i+1);
            int temp = suff[k];
            suff[k] = suff[i];
            suff[i] = temp;
        }
        return suff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
