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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) {
            return NULL;
        }
        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);
        
        vector<int> leftAry(nums.begin(), nums.begin()+mid);
        vector<int> rightAry(nums.begin()+mid+1, nums.end());
        
        root->left = sortedArrayToBST(leftAry);
        root->right = sortedArrayToBST(rightAry);
        
        return root;
    }
};
