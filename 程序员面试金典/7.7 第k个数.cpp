class KthNumber {
public:
    int findKth(int k) {
        int t3=0,t5=0,t7=0;
        vector<int> temp(101,1);
        for(int i=1;i<temp.size();i++){
            temp[i]=min(temp[t3]*3,min(temp[t5]*5,temp[t7]*7));
            if(temp[i]==temp[t3]*3) t3++;
            if(temp[i]==temp[t5]*5) t5++;
            if(temp[i]==temp[t7]*7) t7++;
        }
        return temp[k];
    }
};
