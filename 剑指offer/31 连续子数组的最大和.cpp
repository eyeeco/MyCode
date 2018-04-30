class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size()==0) return 0;
        int num = array[0];
        int temp = array[0];
        for(int i =1;i<array.size();i++){
            temp = max(array[i],temp+array[i]);
            num = max(num,temp);
        }
        return num;
    }
};
