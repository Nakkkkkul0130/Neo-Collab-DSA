
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* constructBinaryTree(vector<int>& coins, int& index) {
    if (index >= coins.size() || coins[index] == -1) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(coins[index]);
    index++;

    node->left = constructBinaryTree(coins, index);
    index++;

    node->right = constructBinaryTree(coins, index);

    return node;
}

int maxGold(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftMax = maxGold(root->left);
    int rightMax = maxGold(root->right);

    return max(root->val, max(leftMax, rightMax));
}

int main() {
    int N;
    cin >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int index = 0;
    TreeNode* root = constructBinaryTree(coins, index);

    int result = maxGold(root);
    cout << result << endl;

    return 0;
}
