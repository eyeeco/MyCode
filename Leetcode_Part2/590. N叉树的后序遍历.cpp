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
    vector<int> postorder(Node* root) {
        if (root==NULL) return vector<int>();
        vector<int> res;
        for (int i=0; i<root->children.size(); i++) {
            vector<int> temp = postorder(root->children[i]);
            if (temp.size()) res.insert(res.end(), temp.begin(), temp.end());
        }
        res.push_back(root->val);
        return res;
    }
};
