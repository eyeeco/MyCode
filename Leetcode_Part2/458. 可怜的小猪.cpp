class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets)/log(k));
    }
};
