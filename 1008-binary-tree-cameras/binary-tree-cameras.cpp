/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*>st;
        int ans=0;

        auto dfs=[&](auto& self,TreeNode* r,TreeNode* pa)->void{
            if(r==nullptr)return;

            self(self,r->left,r);
            self(self,r->right,r);

            if((r->left && !st.count(r->left)) ||
               (r->right && !st.count(r->right))){

                ans++;

                st.insert(pa);
                st.insert(r);
                st.insert(r->left);
                st.insert(r->right);
            }
        };

        dfs(dfs,root,nullptr);

        if(!st.count(root))
            ans++;

        return ans;
    }
};