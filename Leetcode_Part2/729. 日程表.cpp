class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = dict.upper_bound(start);
        if (it != dict.end() && end > it->first) return false;
        if (it != dict.begin() && start < (--it)->second) return false;
        dict[start] = end;
        return true;
    }
    map<int, int> dict;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
