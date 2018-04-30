class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int num=0,a,b;
        for(int i=1;i<=n;i*=10){
            a = n/i;
            b = n%i;
            /*
            if(a%10>=2) num+= (a/10+1)*i;
            else if(a%10==1) num+= a/10*i+b+1;
            else num+= a/10*i;
            */
            num += (a+8)/10*i + (a%10==1)*(b+1);
        }
        return num;
    }
};
