class Solution {
public:
    string addStrings(string num1, string num2) {
        int add = 0,i,j,temp,num2_add;
        if(num2.size()>num1.size()){
            swap(num1,num2);
        }
        for(i=num1.size()-1,j=num2.size()-1;i>=0;i--,j--){
            num2_add = j>=0?num2[j]:'0';
            temp=(num1[i]-'0'+num2_add-'0'+add)%10 +'0';
            add = (num1[i]-'0'+num2_add-'0'+add)/10 ;
            num1[i] = temp;
        }
        if(add>0) num1.insert(num1.begin(),'1');
        return num1;
    }
};
