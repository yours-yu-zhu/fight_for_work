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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return nullptr; //第一步：如果数组大小为零的话，说明是空节点了。+

        int rootValue = postorder[postorder.size() - 1]; //第二步：如果不为空，那么取后序数组最后一个元素作为节点元素。
        TreeNode* root = new TreeNode(rootValue);   //创建根节点
        if(postorder.size() == 1) return root;

        int split_index;
        for(split_index = 0; split_index < inorder.size(); ++split_index){
            if(inorder[split_index] == rootValue) break;
        } //第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点

        //第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
        vector<int> left_inorder(inorder.begin(), inorder.begin() + split_index);
        vector<int> right_inorder(inorder.begin() + split_index + 1, inorder.end());

        //第五步：切割后序数组，切成后序左数组和后序右数组

        vector<int> left_postorder(postorder.begin(), postorder.begin() + left_inorder.size());
        vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end() - 1);
        cout << "_________________________  " << endl;
        cout << "left_inorder: ";
        for(auto i : left_inorder){
            cout << i << " ";
        }
        cout << endl;

        cout << "right_inorder: ";
        for(auto i : right_inorder){
            cout << i << " ";
        }
        cout << endl;

        cout << "left_postorder: ";
        for(auto i : left_postorder){
            cout << i << " ";
        }
        cout << endl;

        cout << "right_postorder: ";
        for(auto i : right_postorder){
            cout << i << " ";
        }
        cout << endl;

        //第六步：递归处理左区间和右区间
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);
    return 0;
}