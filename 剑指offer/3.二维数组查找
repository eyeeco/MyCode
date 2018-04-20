class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int col = array.size(), row = array[0].size();
        int i = 0 , j = row -1 ;
        while( i<row && j>=0){
            if(target == array[i][j] ) return 1;
            else if (array[i][j] < target) i++;
            else j--;
        }
        return 0;
    }
};
