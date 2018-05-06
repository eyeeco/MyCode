class Solution {
public:
    int Add(int num1, int num2)
    {
        int a,b;
        do{
            a = num1 ^ num2 ;
            b = (num1 & num2)<<1 ;
            num1 = a;
            num2 = b;
        }while(b!=0);
        return num1;
    }
};
