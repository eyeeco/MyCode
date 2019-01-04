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
    vector<int> preorder(Node* root) {
        if(root==NULL) return vector<int>();
        stack<Node*> con;
        vector<int> res;
        con.push(root);
        while (!con.empty()) {
            Node* root = con.top();
            con.pop();
            res.push_back(root->val);
            for (int i=root->children.size()-1; i>=0; i--) {
                con.push(root->children[i]);
            }
        }
        return res;
    }
};
