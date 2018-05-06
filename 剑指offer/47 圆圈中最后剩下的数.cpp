class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        queue<int> que;
        if(n==0||m==0) return -1;
        for(int i=0;i<n;i++) que.push(i);
        int point = m,temp;
        while(que.size()>1){
            point--;
            if(point==0) {
                que.pop();
                point = m;
            }else{
                temp = que.front();
                que.pop();
                que.push(temp);
            }
        }
        return que.front();
    }
};
