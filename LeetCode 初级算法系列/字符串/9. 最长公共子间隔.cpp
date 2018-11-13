class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = -1, flag = 1;
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        while(flag){
            pos++;
            if(pos<strs[0].size()){
                char temp = strs[0][pos];
                for(int i=1;i<strs.size();i++){
                    if(pos>=strs[i].size()||strs[i][pos]!=temp){
                        flag=0;
                        break;
                    }
                }

            }else{
                break;
            }
        }
        return strs[0].substr(0,pos);
    }
};
