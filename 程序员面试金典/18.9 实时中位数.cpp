class Middle {
public:
    vector<int> getMiddle(vector<int> A, int n) {
        // write code here
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        vector<int> res;
        for(int num:A){
            if(maxHeap.size()==minHeap.size()){
                if(!minHeap.empty()&&num>minHeap.top()){
                    minHeap.push(num);
                    int temp = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(temp);
                }else{
                    maxHeap.push(num);
                }
            }else{
                if(num>maxHeap.top()){
                    minHeap.push(num);
                }else{
                    maxHeap.push(num);
                    int last = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(last);
                }
            }
            res.push_back(maxHeap.top());
        }
        return res;
    }
};
