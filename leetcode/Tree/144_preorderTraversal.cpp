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
    void qian_xu(TreeNode* root, vector<int>& result){
        if(root == nullptr){
            return;
        }
        result.push_back(root->val);
        qian_xu(root->left, result);
        qian_xu(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        qian_xu(root, result);
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> result = s.preorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "-";
    }
}