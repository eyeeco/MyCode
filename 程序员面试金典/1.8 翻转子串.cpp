class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        string s3 = s1.append(s1);
        if(s3.find(s2)!= string::npos) return true;
        else return false;
    }
};
