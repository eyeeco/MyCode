class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        int res=0;
        if(type==1){
            while(a>1){
                if(a%2==1) res+=b;
                b+= b;
                a = a>> 1;
            }
            return res+b;
        }else if(type==0){
            int p = 0;
            int num = 0;
            while(num<=a){
                num+=b;
                p++;
            }
            return (p-1);
        }else{
            return a+ ~b +1;
        }
    }
};
