class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for(int i = 0; i < n; i++) {
            str += ('1' + i);
        }
        while(--k){
            // next_permutation(str.begin(), str.end());
            next(str);
        }
        return str;
    }
    void next(string& str) {
        int left = -1, right = str.size() - 1;
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] < str[i+1]) {
                left = i;
            }
        }
        if (left == -1) {
            reverse(str.begin(), str.end());
            return ;
        }
        while (str[right] <= str[left]) right--;
        swap(str[left], str[right]);
        reverse(str.begin() + left + 1, str.end());
    }
};
