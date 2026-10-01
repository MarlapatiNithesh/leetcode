class Pair{
    char ch;
    int pos;

    Pair(char ch,int pos){
        this.ch=ch;
        this.pos=pos;
    }
}

class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        Deque<Pair> st=new ArrayDeque<>();
        int[] mark=new int[seq.length()];

        int maxDepth=0;
        int depth=0;

        for(int i=0;i<seq.length();i++){
            if(seq.charAt(i)=='('){
                depth++;
                maxDepth=Math.max(maxDepth,depth);
            }else{
                depth--;
            }
        }

        int half=(maxDepth+1)/2;

        for(int i=0;i<seq.length();i++){
            char c=seq.charAt(i);

            if(c=='('){
                st.push(new Pair(c,i));

                if(st.size()>half){
                    mark[i]=1;
                }
            }else{
                Pair p=st.pop();

                if(st.size()+1>half){
                    mark[p.pos]=1;
                    mark[i]=1;
                }
            }
        }

        return mark;
    }
}