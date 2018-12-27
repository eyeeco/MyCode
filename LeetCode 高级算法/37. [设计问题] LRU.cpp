class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {
    }

    int get(int key) {
        if (con.count(key)) {
            touch(key);
            con[key] = make_pair(con[key].first, used.begin());
            return con[key].first;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (con.count(key)) {
            touch(key);
        } else {
            if (used.size() == cap) {
                int last_key = used.back();
                con.erase(last_key);
                used.pop_back();
            }
            used.push_front(key);
        }
        con[key] = make_pair(value, used.begin());
    }

private:
    int cap;
    list<int> used;
    typedef pair<int, list<int>::iterator> Rec;
    unordered_map<int, Rec> con;

    void touch (int key) {
        Rec item = con[key];
        used.erase(item.second);
        used.push_front(key);
        item.second = used.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
