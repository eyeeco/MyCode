class Solution {
public:
	int StrToInt(string str) {
		int sum = 0;
		int i = 0;
		if (str[i] == '+' || str[i] == '-') i++;
		while(i<str.size()){
			if ((str[i] - '0')<0 || (str[i] - '0')>9) return 0;
			sum *= 10;
			sum += (str[i] - '0');
			i++;
		}
		sum = str[0] == '-' ? -sum : sum;
		return sum;
	}
};
