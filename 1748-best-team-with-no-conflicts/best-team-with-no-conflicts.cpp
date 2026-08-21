class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> pa;

        for(int i = 0; i < scores.size(); i++){
            pa.push_back({ages[i], scores[i]});
        }

        sort(pa.begin(), pa.end());

        vector<int> sc;

        for(auto it : pa){
            sc.push_back(it.second);
        }

        vector<int> a;

        for(int i = 0; i < scores.size(); i++){
            a.push_back(sc[i]);

            for(int j = 0; j < i; j++){
                if(sc[j] <= sc[i]){
                    a[i] = max(a[i], a[j] + sc[i]);
                }
            }
        }

        int s = 0;

        for(auto it : a){
            s = max(s, it);
        }

        return s;
    }
};