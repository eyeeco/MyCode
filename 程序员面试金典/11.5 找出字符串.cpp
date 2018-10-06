class Finder {
public:
    int findString(vector<string> str, int n, string x) {
        // write code here
        int left = 0,right = str.size()-1;
        while(left<right){
            int mid = (left+right)/2;
            if(str[mid]==""){
                int l = mid-1,r = mid+1;
                while(l>=left||r<=right){
                    if(l>=left&&str[l]!=""){
                        mid = l;
                        break;
                    }
                    if(r<=right&&str[r]!=""){
                        mid = r;
                        break;
                    }
                    l--;
                    r++;
                }
            }
            if(str[mid]==x) return mid;
            else if(str[mid]<x) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};
