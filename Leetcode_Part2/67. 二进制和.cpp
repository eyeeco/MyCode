class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int ad = 0;
        string res;
        while (i >= 0 && j >= 0) {
            res += (char)('0' + (a[i]-'0'+b[j]-'0'+ad) % 2);
            ad = (a[i]-'0'+b[j]-'0'+ad) / 2;
            i--; j--;
        }
        while (i >= 0) {
            res += (char)('0'+(a[i]-'0'+ad) % 2);
            ad = (a[i]-'0'+ad) / 2;
            i--;
        }
        while (j >= 0) {
            res += (char)('0'+(b[j]-'0'+ad) % 2);
            ad = (b[j]-'0'+ad) / 2;
            j--;
        }
        if (ad) res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};
