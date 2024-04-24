#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Solution {
public:
    //递归法
    bool compare(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right != nullptr) return false;
        else if(left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
    //迭代法
    bool isSymmetric_2(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode* curleft = que.front();
            que.pop();
            TreeNode* curright = que.front();
            que.pop();
            if(!curleft && !curright) continue;
            if(curleft == nullptr && curright != nullptr) return false;
            else if(curleft != nullptr && curright == nullptr) return false;
            else if(curleft->val != curright->val) return false;

            que.push(curleft->left);
            que.push(curright->right);

            que.push(curleft->right);
            que.push(curright->left);
        }
        return true;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution s;
    cout << s.isSymmetric(root) << endl;
}