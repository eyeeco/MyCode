class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        int blank = 0;
        for(int i=0;i<length;i++){
            if(iniString[i]==' ') blank++;
        }
        int newlength = length+blank*2;
        iniString.resize(newlength);
        for(int i=length-1;i>=0;i--){
            if(iniString[i] != ' '){
                iniString[--newlength] = iniString[i];
            }else{
                iniString[--newlength] = '0';
                iniString[--newlength] = '2';
                iniString[--newlength] = '%';
            }
        }
        return iniString;
    }
};
