class BinDecimal {
public:
    string printBin(double num) {
        // write code here
        string res = "0.";
        if(num<=0||num>=1) return "Error";
        while(num){
            if(res.size()>=34) return "Error";
            num*=2;
            if(num>=1){
                res.append("1");
                num-=1;
            }else{
                res.append("0");
            }
        }
        return res;
    }
};
