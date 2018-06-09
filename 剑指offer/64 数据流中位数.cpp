class Solution {
private:
    priority_queue<int,vector<int>,less<int>> p;
    priority_queue<int,vector<int>,greater<int>> q;
public:
    void Insert(int num)
    {
        if(p.empty()||num<=p.top()) p.push(num);
        else q.push(num);
        if(p.size()==q.size()+2){q.push(p.top());p.pop();}
        if(p.size()+1==q.size()){p.push(q.top());q.pop();}
    }

    double GetMedian()
    {
        if(p.empty()) return 0;
        if((p.size()+q.size())%2==1) return p.top();
        else return (p.top()+q.top())/2.0;
    }

};
