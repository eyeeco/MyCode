class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while(A&B){
            int a = A ^ B;
            int b = (A & B) << 1;
            A = a;
            B = b;
        }
        return A|B;
    }
};
