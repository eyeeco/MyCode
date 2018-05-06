class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int start = 0,end = array.size()-1;
        int res;
        vector<int> output;
        while(start<end){
            res = array[start]+array[end];
            if(res==sum) {
                output.push_back(array[start]);
                output.push_back(array[end]);
                return output;
            }else if(res<sum){
                start++;
            }else{
                end--;
            }
        }
        return output;
    }
};
