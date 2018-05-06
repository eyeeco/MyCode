class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int start=1,end=2;
        int local ;
        vector<vector<int>> res;
        vector<int> temp;
        while(start<=sum/2){
            local = (start + end)*(end-start+1)/2;
            if(local==sum){
                temp.clear();
                for(int i=start;i<=end;i++){temp.push_back(i);}
                res.push_back(temp);
                start++;end++;
            }else if(local<sum){
                end++;
            }else{
                start++;
            }
        }
        return res;
    }
};
