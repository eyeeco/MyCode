class Zipper {
public:
    string zipString(string iniString) {
        string s;
        int i=0,j=0;
        while(i<iniString.size()){
            while(iniString[i]==iniString[j]) j++;
            s+=iniString[i];
            s+=to_string(j-i);
            i = j;
        }
        if(s.size()<iniString.size()) return s;
        else return iniString;
    }
};
