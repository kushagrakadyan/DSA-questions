/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    int preindex=0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end){

        if(start>end) return NULL;
        //phele ko root me stor karaegne
        int element=preorder[preindex];
        preindex++;

        TreeNode* root=new TreeNode(element);

        //root ko inorder me dhundenge
        int position=mp[element];

        //root ke left elements ko left tree me dalna hai
        root->left=solve(preorder,inorder,start,position-1);
        //right me bhi

        root->right=solve(preorder,inorder,position+1,end);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,inorder.size()-1);

    }
};