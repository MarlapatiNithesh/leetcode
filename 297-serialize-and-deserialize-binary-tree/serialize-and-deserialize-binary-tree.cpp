/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "null";
        string res="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();q.pop();
            if(it){
                res+=to_string(it->val)+",";
                q.push(it->left);
                q.push(it->right);
            }else{
                res+="null,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null")return nullptr;
        stringstream ss(data);
        string token;
        getline(ss,token,',');
        TreeNode* root=new TreeNode(stoi(token));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();q.pop();
            if(!getline(ss,token,','))break;
            if(token!="null"){
                it->left=new TreeNode(stoi(token));
                q.push(it->left);
            }
            if(!getline(ss,token,','))break;
            if(token!="null"){
                it->right=new TreeNode(stoi(token));
                q.push(it->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));