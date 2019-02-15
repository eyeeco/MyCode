class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        for(int i=0, j=0; i<name.size(); i++, j++){
            if(j>typed.size()-1 || name[i] != typed[j]) return false;
            if(i!=name.size()-1 && name[i] != name[i+1]){
                while(j!=typed.size()-1&&typed[j]==typed[j+1]){
                    j++;
                }
            }
        }
        return true;
    }
};
