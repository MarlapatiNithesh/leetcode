class Solution {
public:
    vector<pair<int,int>> intervals;
    vector<pair<int,int>> temp,result;
    int n;
    
    void solve(int i,int end){
        if(i>=n){
            if(temp.size()>result.size())
                result=temp;
            return;
        }

        // not take
        solve(i+1,end);

        // take
        if(intervals[i].first>end){
            temp.push_back(intervals[i]);

            solve(i+1,intervals[i].second);

            temp.pop_back();
        }
    }

    vector<string> maxNumOfSubstrings(string s) {
        int len=s.size();

        vector<int> first(26,len),last(26,-1);

        for(int i=0;i<len;i++){
            int c=s[i]-'a';
            first[c]=min(first[c],i);
            last[c]=i;
        }

        for(int c=0;c<26;c++){
            if(last[c]==-1) continue;

            int l=first[c];
            int r=last[c];
            bool valid=true;

            for(int i=l;i<=r;i++){
                int x=s[i]-'a';

                if(first[x]<l){
                    valid=false;
                    break;
                }

                r=max(r,last[x]);
            }

            if(valid)
                intervals.push_back({l,r});
        }

        sort(intervals.begin(),intervals.end());

        n=intervals.size();

        solve(0,-1);

        vector<string> ans;

        for(auto [l,r]:result)
            ans.push_back(s.substr(l,r-l+1));

        return ans;
    }
};