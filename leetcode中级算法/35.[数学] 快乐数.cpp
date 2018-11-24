class Solution {
public:
    int getNum(int n){
        int sum = 0;
        while(n){
            int temp = n%10;
            sum += temp*temp;
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        set<int> con = {4,16,37,58,89,145,42,20};
        while(n!=1){
            n = getNum(n);
            if(con.count(n)) return false;
        }
        return true;
    }
};
