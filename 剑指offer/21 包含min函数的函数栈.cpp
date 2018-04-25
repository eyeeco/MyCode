class Solution {
private:
    stack<int> data, sup;
public:
    void push(int value) {
        data.push(value);
        if(sup.size()==0||value<sup.top()) sup.push(value);
        else sup.push(sup.top());
    }
    void pop() {
        data.pop();
        sup.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return sup.top();
    }
};
