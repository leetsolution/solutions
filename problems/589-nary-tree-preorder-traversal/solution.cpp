/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) return result;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            result.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--) {
                s.push(node->children[i]);
            }
        }
        return result;
    }
};