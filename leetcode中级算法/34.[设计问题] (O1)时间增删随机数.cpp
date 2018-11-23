class RandomizedSet {
public:
    unordered_map<int,int> hash;
    vector<int> con;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.count(val)){
            return false;
        }else{
            con.push_back(val);
            hash[val] = con.size()-1;
            return true;
        }

    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.count(val)){
            int pos = hash[val];
            hash[con.back()] = hash[val];
            con[pos] = con.back();
            con.pop_back();
            hash.erase(val);
            return true;
        }else{
            return false;
        }

    }

    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand()%con.size();
        return con[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
