class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> desk;
        vector<int> res(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!desk.empty()&&temperatures[i]>=temperatures[desk.top()]) desk.pop();
            if(desk.empty()) res[i] = 0; else res[i] = desk.top()-i;
            desk.push(i);
        }
        return res;
    }
};
