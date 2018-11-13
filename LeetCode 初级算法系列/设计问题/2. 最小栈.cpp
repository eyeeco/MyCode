class MinStack {
public:
    stack<int> con;
    stack<int> mcon;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        con.push(x);
        if(mcon.empty()||x<=mcon.top()){
            mcon.push(x);
        }
    }

    void pop() {
        int temp = con.top();
        con.pop();
        if(temp==mcon.top())
            mcon.pop();
    }

    int top() {
        return con.top();
    }

    int getMin() {
        return mcon.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
