class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (v1.size()==v2.size()) {
            if (v1.empty()||num>=v1.top()) {
                v1.push(num);
            } else {
                v2.push(num);
                int temp = v2.top();
                v2.pop();
                v1.push(temp);
            }
        } else {
            if (num>v1.top()) {
                v1.push(num);
                int temp = v1.top();
                v2.push(temp);
                v1.pop();
            } else {
                v2.push(num);
            }
        }
    }

    double findMedian() {
        if(v1.size()==v2.size()) {
            return (v1.top()+v2.top())/2.0;
        } else {
            return v1.top();
        }
    }
private:
    priority_queue<int,vector<int>,greater<int>> v1;
    priority_queue<int> v2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
