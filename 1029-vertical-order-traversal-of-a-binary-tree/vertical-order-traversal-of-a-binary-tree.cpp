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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;

        auto dfs=[&](auto& self,TreeNode* r,int h,int row)->void{
            if(r==nullptr)return;

            mp[h].push_back({row,r->val});

            self(self,r->left,h-1,row+1);
            self(self,r->right,h+1,row+1);
        };

        dfs(dfs,root,0,0);

        vector<vector<int>>ans;

        for(auto &[h,v]:mp){
            sort(v.begin(),v.end());

            vector<int>temp;
            for(auto &[row,val]:v)
                temp.push_back(val);

            ans.push_back(temp);
        }

        return ans;
    }
};