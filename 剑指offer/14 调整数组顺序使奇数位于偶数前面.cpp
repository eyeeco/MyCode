class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> title,tile;
        for(int i=0;i<array.size();i++){
            if(array[i]%2==1) title.push_back(array[i]);
            else tile.push_back(array[i]);
        }
        for(int i=0;i<tile.size();i++){
            title.push_back(tile[i]);
        }
        array = title;
    }
};
