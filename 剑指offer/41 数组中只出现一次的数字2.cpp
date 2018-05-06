class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2) return ;
        int point = 0;
        for(int i=0;i<data.size();i++){
            point ^= data[i];
        }
        int tip=0;
        while((point & (1<<tip))==0){
            tip++;
        }
        for(int i=0;i<data.size();i++){
            if(data[i] & (1<<tip)) *num1 ^= data[i];
            else *num2 ^= data[i];
        }
    }
};
