class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5) return false;
        vector<int> temp(14,0);
        int maxN = -1;
        int minN = 15;
        for(int i=0;i<numbers.size();i++){
            temp[numbers[i]]++;
            if(numbers[i]==0) continue;
            if(temp[numbers[i]]>1) return false;
            maxN = max(maxN,numbers[i]);
            minN = min(minN,numbers[i]);
        }
        return (maxN-minN)<5 ;
    }
};
