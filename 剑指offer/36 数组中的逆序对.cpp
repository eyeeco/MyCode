class Solution {
private:
    long long sum = 0;
public:
    void merge(vector<int> &data, int start, int mid,int end, vector<int> &res){
        int i=start;
        int j=mid+1;
        int t=0;
        while(i<=mid&&j<=end){
            if(data[i]<=data[j]) res[t++] = data[i++] ;
            else{
                res[t++] = data[j++];
                sum += (mid-i+1);
            }
        }
        while(i<=mid){
            res[t++] = data[i++];
        }
        while(j<=end){
            res[t++] = data[j++];
        }
        t = 0;
        while(start<=end){
            data[start++] = res[t++];
        }
        sum %= 1000000007;
    }
    void Merge_sort(vector<int> &data, int start, int end, vector<int> &res){
        if(start<end){
            int mid = (start+end)/2;
            Merge_sort(data,start,mid,res);
            Merge_sort(data,mid+1,end,res);
            merge(data,start,mid,end,res);
        }
    }
    int InversePairs(vector<int> data) {
        vector<int> res(data);
        Merge_sort(data,0,data.size()-1,res);
        return (int)sum;
    }

};
