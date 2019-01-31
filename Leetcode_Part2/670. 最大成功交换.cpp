class Solution {
public:
    int maximumSwap(int num) {
        vector<int> rs;
        vector<int> ms;
        int temp = 0, i=0;
        while(num){
            int n = num%10;
            rs.push_back(n);
            temp = max(temp, n);
            ms.push_back(temp);
            num /= 10;
        }
        i = rs.size()-1;
        while(i>=0){
            if(rs[i]==ms[i]) i--;
            else{
                temp = rs[i];
                rs[i] = ms[i];
                int len = 0;
                while(len<rs.size()&&rs[len]!=ms[i]) len++;
                rs[len] = temp;
                break;
            }
        }
        temp = 0;
        for(int i=rs.size()-1; i>=0; i--){
            temp = temp*10 + rs[i];
        }
        return temp;
    }
};
