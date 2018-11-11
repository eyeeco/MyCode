class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 0;
        for(int i=digists.size()-1;i>=0;i--){
            if(i==digists.size()-1||plus) {
                plus = (digists[i]+1)/10;
                digists[i] = (digists[i]+1)%10;
            }
        }
        if(plus==1) digits.insert(digits.begin(),1);
        return digits;
    }
};
