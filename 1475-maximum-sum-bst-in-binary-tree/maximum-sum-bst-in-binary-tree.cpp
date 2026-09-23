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

    enum type {
        BST,
        NOT_BST
    };

    class Node {
    public:
        int sum;
        int mn;
        int mx;
        type t;

        Node(int sum,int mn,int mx,type t) {
            this->sum=sum;
            this->mn=mn;
            this->mx=mx;
            this->t=t;
        }
    };

    int ans=0;

    Node dfs(TreeNode* r) {
        if(r==nullptr)
            return Node(0,INT_MAX,INT_MIN,BST);

        Node l=dfs(r->left);
        Node rr=dfs(r->right);

        if(l.t==BST && rr.t==BST &&
           l.mx<r->val && r->val<rr.mn) {

            int sum=l.sum+rr.sum+r->val;

            ans=max(ans,sum);

            int mn=min(l.mn,r->val);
            int mx=max(rr.mx,r->val);

            return Node(sum,mn,mx,BST);
        }

        return Node(0,INT_MIN,INT_MAX,NOT_BST);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};