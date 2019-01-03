class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> con;
        vector<int> res;
        sort(deck.begin(), deck.end(), greater<int>());
        for (int i=0; i<deck.size(); i++) {
            if (con.empty()) con.push_back(deck[i]);
            else {
                int temp = con.back();
                con.pop_back();
                con.push_front(temp);
                con.push_front(deck[i]);
            }
        }
        for (int item : con) {
            res.push_back(item);
        }
        return res;
    }
};
