class LongestString {
public:
    bool canBuild(string s, map<string,bool> hash,bool ori){
        if(ori&&hash[s]) return true;
        for(int i=0;i<s.size();i++){
            string left = s.substr(0,i);
            string right = s.substr(i);
            if(hash[left]&&canBuild(right,hash,true)){
                return true;
            }
        }
        return false;
    }
    int getLongest(vector<string> str, int n) {
        // write code here
        map<string,bool> hash;
        int size=0;
        for(string s:str){
            hash[s] = true;
        }
        for(string s:str){
            if(canBuild(s,hash,false))
            {
                int len = s.size();
                size = max(size, len);
            }
        }
        return size;
    }
};
