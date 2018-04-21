class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0 ) return ;
        int orilength = 0;
        int newlength = 0;
        int i = 0;
        while(str[i]!='\0'){
            if(str[i]==' ') newlength+=2;
            i++;
        }
        orilength += i;
        newlength += i;
        while(orilength>=0&&orilength<newlength){
            if(str[orilength]==' '){
                str[newlength--] = '0';
                str[newlength--] = '2';
                str[newlength--] = '%';
            }else{
                str[newlength--] = str[orilength];
            }
            orilength--;
        }
	}
};


// 替换空格
