/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> con;
        if(root==NULL) return vector<vector<int>>();
        con.push(root);
        vector<vector<int>> res;
        vector<int> temp;
        int curr = 1, next = 0;
        while (!con.empty()) {
            Node* pt = con.front();
            con.pop();
            temp.push_back(pt->val);
            curr--;
            for (int i=0; i<pt->children.size(); i++) {
                con.push(pt->children[i]);
                next++;
            }
            if (!curr) {
                curr = next;
                next = 0;
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};
