class Count2 {
public:
    int countNumberOf2s(int n) {
        // write code here
        string c = to_string(n);
        int len = c.size();
        int num = 0;
        for(int i=0;i<len;i++){
            int t = c[i] - '0';
            int m = pow(10,len-i-1);
            int g = pow(10,len-i);
            if(t>2)
                num+= (n/g+1) * m;
            else if(t<2)
                num+= n/g * m;
            else
                num+= n/g * m + n%m + 1;
        }
        return num;
    }
};
