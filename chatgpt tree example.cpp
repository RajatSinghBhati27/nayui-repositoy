#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    Solution a;

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is: \n";
    vector<vector<int>> result = a.levelOrder(root);
    for (const auto& level : result) {
        for (const auto& val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
