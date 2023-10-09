#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* buildBST(const vector<int>& vehicleIDs) {
    TreeNode* root = nullptr;
    for (int id : vehicleIDs) {
        root = insert(root, id);
    }
    return root;
}
bool areBSTsIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    return (root1->val == root2->val) &&
           areBSTsIdentical(root1->left, root2->left) &&
           areBSTsIdentical(root1->right, root2->right);
}

int main() {
    string inputA, inputB;
    getline(cin, inputA);
    getline(cin, inputB);

    vector<int> vehicleIDsA, vehicleIDsB;

   
    istringstream issA(inputA);
    int idA;
    while (issA >> idA && idA != -1) {
        vehicleIDsA.push_back(idA);
    }

    istringstream issB(inputB);
    int idB;
    while (issB >> idB && idB != -1) {
        vehicleIDsB.push_back(idB);
    }

    TreeNode* rootA = buildBST(vehicleIDsA);
    TreeNode* rootB = buildBST(vehicleIDsB);

    if (areBSTsIdentical(rootA, rootB)) {
        cout << "Both vehicle fleets are identical" << endl;
    } else {
        cout << "Vehicle fleets are not identical" << endl;
    }

    return 0;
}
