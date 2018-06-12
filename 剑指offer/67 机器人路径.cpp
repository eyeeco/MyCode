class Solution {
public:
    int num(int k){
        int sum = 0;
        while(k){
            sum+= k%10;
            k/=10;
        }
        return sum;
    }
    int helper(int threshold, int rows, int cols,int i,int j,vector<int>& vis){
        int index = cols * i + j ;
        if(i<0||i>=rows||j<0||j>=cols||num(i)+num(j)>threshold||vis[index]==1) return 0;
        vis[index] = 1;
        return 1+ helper(threshold,rows,cols,i-1,j,vis)
                + helper(threshold,rows,cols,i+1,j,vis)
                + helper(threshold,rows,cols,i,j-1,vis)
                + helper(threshold,rows,cols,i,j+1,vis);
    }
    int movingCount(int threshold, int rows, int cols)
    {
        vector<int> vis(rows*cols,0);
        return helper(threshold,rows,cols,0,0,vis);
    }
};
