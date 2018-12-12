class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size()+num2.size());
        string mul_res;
        int flag= 1;
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                int p1 = i+j, p2= i+j+1;
                int mul = (num1[i]-'0')*(num2[j]-'0');
                res[p2]+= mul;
                res[p1]+= res[p2]/10;
                res[p2]%= 10;
            }
        }
        for(int i=0;i<res.size();i++){
            if(flag&&res[i]==0){
                continue;
            }
            else{
                mul_res+= (char)(res[i]+'0');
                flag=0;
            }
        }
        return mul_res.size()?mul_res:"0";
    }
};
