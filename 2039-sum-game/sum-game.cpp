class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();

        int cnt1=count(num.begin(),num.begin()+n/2,'?');
        int cnt2=count(num.begin()+n/2,num.end(),'?');

        int s1=0,s2=0;

        for(int i=0;i<n/2;i++){
            if(num[i]!='?')s1+=num[i]-'0';
        }

        for(int i=n/2;i<n;i++){
            if(num[i]!='?')s2+=num[i]-'0';
        }

        if((cnt1+cnt2)%2)return true;

        return s1-s2!=(cnt2-cnt1)*9/2;
    }
};