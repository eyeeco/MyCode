class Reverse {
public:
    string reverseString(string iniString) {
        char temp;
        int len = iniString.size();
        for(int i=0;i<len/2;i++){
            temp = iniString[i];
            iniString[i] = iniString[len-i-1];
            iniString[len-i-1] = temp;
        }
        return iniString;
    }
};
