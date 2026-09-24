struct Node{
    int cnt[5]={0};
    int prod=0;
    int sz=0;
};

class SegTree{
public:
    vector<Node>sg;
    vector<int>nums;
    int n,k;

    SegTree(int n,int k,vector<int>&a){
        this->n=n;
        this->k=k;
        this->nums=a;
        sg.resize(4*n);
        build(0,n-1,0);
    }

    void build(int l,int r,int idx){
        if(l==r){
            make_leaf(idx,l);
            return;
        }
        int mid=l+(r-l)/2;
        build(l,mid,2*idx+1);
        build(mid+1,r,2*idx+2);
        sg[idx]=mergeNode(sg[2*idx+1],sg[2*idx+2]);
    }

    void make_leaf(int idx,int l){
        Node lf;
        lf.prod=nums[l]%k;
        lf.cnt[nums[l]%k]=1;
        lf.sz=1;
        sg[idx]=lf;
    }

    Node mergeNode(Node left,Node right){
        if(left.sz==0)return right;
        if(right.sz==0)return left;

        Node result;
        result.prod=(left.prod*right.prod)%k;
        result.sz=left.sz+right.sz;

        for(int i=0;i<5;i++){
            result.cnt[i]+=left.cnt[i];
        }

        for(int i=0;i<5;i++){
            int newProd=(left.prod*i)%k;
            result.cnt[newProd]+=right.cnt[i];
        }

        return result;
    }

    void segTreeUpdate(int l,int r,int idx,int pos,int val){
        if(l==r){
            nums[l]=val;
            make_leaf(idx,l);
            return;
        }

        int mid=l+(r-l)/2;

        if(pos<=mid){
            segTreeUpdate(l,mid,2*idx+1,pos,val);
        }else{
            segTreeUpdate(mid+1,r,2*idx+2,pos,val);
        }

        sg[idx]=mergeNode(sg[2*idx+1],sg[2*idx+2]);
    }

    Node segTreeQuery(int l,int r,int ql,int qr,int idx){
        if(ql>r || qr<l){
            Node ep;
            return ep;
        }

        if(ql<=l && r<=qr){
            return sg[idx];
        }

        int mid=l+(r-l)/2;

        Node left=segTreeQuery(l,mid,ql,qr,2*idx+1);
        Node right=segTreeQuery(mid+1,r,ql,qr,2*idx+2);

        return mergeNode(left,right);
    }

    void update(int pos,int val){
        segTreeUpdate(0,n-1,0,pos,val);
    }

    Node query(int ql,int qr){
        return segTreeQuery(0,n-1,ql,qr,0);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums,int k,vector<vector<int>>& queries){
        int n=nums.size();
        vector<int>ans;
        SegTree sg(n,k,nums);

        for(auto it:queries){
            int idx=it[0],val=it[1],st=it[2],x=it[3];

            sg.update(idx,val);

            Node res=sg.query(st,n-1);
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};