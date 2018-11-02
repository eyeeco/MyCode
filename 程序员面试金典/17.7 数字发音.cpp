
class ToString {
private:
	vector<string> digits;
	vector<string> teens ;
	vector<string> tens;
	vector<string> th;
public:
	ToString(){
		digits = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
		teens = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		tens = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		th = {"", " Thousand,", " Million,"};
	};
	string base(int x){
		string res;
		if (x>100){
			res += digits[x / 100 - 1] + " Hundred ";
			x %= 100;
		}
		if (x >= 11 && x <= 19){
			res += teens[x % 10 - 1];
			return res;
		}
		else if (x == 10 || x >= 20){
			res += tens[x / 10 - 1] ;
			x = x % 10;
            if(x!=0) res += " ";
		}
		if (x >= 1 && x <= 9){
			res = res + digits[x % 10 - 1];
		}
		return res;
	}
	string toString(int x) {
		// write code here
		string res;
		if (x == 0) res = "Zero";
		int i = 0;
		while (x){
            if(x%1000!=0) res = base(x % 1000) + th[i] + res;
			x /= 1000;
            i++;
		}
        char p = res[res.length()-1];
        if(p==','){
            res = res.substr(0,res.length()-1);
        }
		return res;
	}
};
