#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Node của cây
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Thêm node vào cây
void insert(Node* &root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }

    if (val < root->val) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

// Xuất ra node của cây theo BFS
void bfs(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            Node* curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}

int main() {
    Node* root = NULL;
    int n, x;
    // Số lượng phần tử của mảng
    cin >> n;
    for (int i = 0; i < n; i++) {
        // Phần tử của mảng
        cin >> x;
        insert(root, x);
    }
    cout << "BFS order: ";
    bfs(root);
    return 0;
}