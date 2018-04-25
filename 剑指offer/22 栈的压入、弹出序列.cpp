class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> test;
        for(int i=0,j=0;i<pushV.size();i++){
            test.push(pushV[i]);
            while(j<popV.size()&&test.top()==popV[j]){
                test.pop();
                j++;
            }
        }
        return test.empty();
    }
};
