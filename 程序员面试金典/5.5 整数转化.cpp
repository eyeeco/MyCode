class Transform {
public:
    int calcCost(int A, int B) {
        int count = 0;
        for(int i=A^B;i!=0;i = i&(i-1)){
            count++;
        }
        return count;
    }
};
