class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0,sum=0,num;
        auto it = flowerbed.begin();
        it = flowerbed.insert(it,0);
        flowerbed.push_back(0);
        while(i<flowerbed.size()){
            num=0;
            while(flowerbed[i]==0&&i<flowerbed.size()){
                num++;
                i++;
            }
            if(num>2) sum+=(num-1)/2;
            i++;
        }
        return sum>=n;
    }
};
