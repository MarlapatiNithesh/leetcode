class Solution{
public:
    vector<int>ans,temp;
    vector<vector<int>>best;

    void dfs(vector<int>&personMask,int idx,int mask,int fullmask){
        if(mask==fullmask){
            if(ans.empty()||temp.size()<ans.size())
                ans=temp;
            return;
        }

        if(idx==personMask.size())return;

        if(best[idx][mask]<=temp.size())return;

        best[idx][mask]=temp.size();

        dfs(personMask,idx+1,mask,fullmask);

        int newmask=mask|personMask[idx];

        if(newmask!=mask){
            temp.push_back(idx);

            dfs(personMask,idx+1,newmask,fullmask);

            temp.pop_back();
        }
    }

    vector<int>smallestSufficientTeam(vector<string>&req_skills,vector<vector<string>>&people){
        int n=req_skills.size();
        int m=people.size();

        int fullmask=(1<<n)-1;

        unordered_map<string,int>mp;

        for(int i=0;i<n;i++)
            mp[req_skills[i]]=i;

        vector<int>personMask(m,0);

        for(int i=0;i<m;i++){
            for(auto &s:people[i])
                personMask[i]|=(1<<mp[s]);
        }

        best.assign(m+1,vector<int>(1<<n,61));

        ans.clear();
        temp.clear();

        dfs(personMask,0,0,fullmask);

        return ans;
    }
};