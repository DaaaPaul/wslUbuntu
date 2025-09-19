#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
        
    int a, b = 0;
    if(root->left) a = maxDepth(root->left);
    if(root->right) b = maxDepth(root->right);
    
    if(a > b) return a + 1;
    else return b + 1;
}

int main() {
	TreeNode x(1), y(2);
	TreeNode* xp = &x, *yp = &y;
	xp->right = yp;
	std::cout << maxDepth(xp);
}
