class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int n=s.size();
        vector<int>order;
        string st="";

        for(int i=n-1;i>=0;i--){
            if(s[i]=='-'){
                if(st=="") continue;
                reverse(st.begin(),st.end());
                order.push_back(stoi(st));
                st="";
            }else st+=s[i];
        }
        reverse(st.begin(),st.end());
        order.push_back(stoi(st));
        reverse(order.begin(),order.end());

        int sz=order.size();
        vector<int>depth(sz);
        depth[0]=0;

        int id=1,cnt=0;
        for(int i=1;i<n;i++){
            if(isdigit(s[i])){
                if(cnt){
                    depth[id++]=cnt;
                    cnt=0;
                }
            }else cnt++;
        }

        TreeNode* root=new TreeNode(order[0]);
        int idx=1;

        auto dfs=[&](auto &self,TreeNode* r,int prev)->void{
            if(idx>=sz) return;

            if(depth[idx]==prev+1){
                r->left=new TreeNode(order[idx]);
                idx++;
                self(self,r->left,prev+1);
            }

            if(idx>=sz) return;

            if(depth[idx]==prev+1){
                r->right=new TreeNode(order[idx]);
                idx++;
                self(self,r->right,prev+1);
            }
        };

        dfs(dfs,root,0);
        return root;
    }
};