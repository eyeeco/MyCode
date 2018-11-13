/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sorted(vector<int> nums, int left, int right){
        if(left>=right){
            if(left>right) return NULL;
            TreeNode* root = new TreeNode(nums[left]);
            return root;
        }else{
            int k = (left+right)/2;
            TreeNode* root = new TreeNode(nums[k]);
            root->left = sorted(nums,left,k-1);
            root->right = sorted(nums,k+1,right);
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums,0,nums.size()-1);
    }
};
