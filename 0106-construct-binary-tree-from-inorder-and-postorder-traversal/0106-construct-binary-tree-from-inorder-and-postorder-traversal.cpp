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
    int postindex;

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start,int end){
        if(start>end) return NULL;
        //phele ko root me stor karaegne
        int element=postorder[postindex];
        postindex--;

        TreeNode* root=new TreeNode(element);

        //root ko inorder me dhundenge
        int position=mp[element];

        //root ke left elements ko left tree me dalna hai
        root->right=solve(inorder,postorder,position+1,end); 
        //right me bhi
        root->left=solve(inorder,postorder,start,position-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        postindex=postorder.size()-1;
        return solve(inorder,postorder,0,inorder.size()-1);
    }
};