class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if(numerator==0) return "0";
        if((numerator<0)^(denominator<0)){
            res+= "-";
        }
        long long num1 = abs((long long)numerator);
        long long num2 = abs((long long)denominator);
        res += to_string(num1/num2);
        num1 = num1%num2;
        if(num1==0){
            return res;
        }
        map<long long,long long> mymap;
        res += ".";
        mymap[num1] = res.size();
        while(num1!=0){
            num1 = num1 *10;
            res+= to_string(num1/num2);
            num1%= num2;
            if(mymap.count(num1)){
                int index = mymap[num1];
                res.insert(res.begin()+index,'(');
                res+=")";
                break;
            }else{
                mymap[num1] = res.size();
            }
        }
        return res;
    }
};
