class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int num=0,time=0;
        for(int i=0;i<numbers.size();i++){
            if(time==0) num = numbers[i];
            if(num == numbers[i]) time++;
            else time--;
        }
        time = 0;
        for(auto i : numbers){
            if(i==num) time++;
        }
        return time>numbers.size()/2?num:0;
    }
};
