class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        con.push_back(t);
        while(con.back()-con.front()>3000) con.pop_front();
        return con.size();
    }
    deque<int> con;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
