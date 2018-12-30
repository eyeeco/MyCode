class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> c_gas(gas), c_cost(cost);
        c_gas.insert(c_gas.end(),gas.begin(), gas.end());
        c_cost.insert(c_cost.end(),cost.begin(), cost.end());
        int i = 0;
        while (i < gas.size()) {
            int left = 0;
            for (int j=i; j-i< gas.size(); j++) {
                left += c_gas[j] - c_cost[j];
                if (left < 0) break;
            }
            if (left>=0) return i;
            i++;
        }
        i = c_gas.size()-1;
        while (i>=gas.size()) {
            int left = 0;
            for (int j=i; i-j< gas.size(); j--) {
                left += c_gas[j] - c_cost[j];
                if (left < 0) break;
            }
            if (left>=0) return i-gas.size();
            i--;
        }
        return -1;
    }
};
