class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0; i<input.size(); i++){
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
                vector<int> r1 = diffWaysToCompute(input.substr(0, i));
                vector<int> r2 = diffWaysToCompute(input.substr(i+1));
                for(int n1:r1){
                    for(int n2:r2){
                        if(input[i]=='+') res.push_back(n1+n2);
                        else if(input[i]=='-') res.push_back(n1-n2);
                        else res.push_back(n1*n2);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        return res;
    }
};
