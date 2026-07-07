/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            parent[root->left]=root;
            inorder(root->left);
        }
        if(root->right!=NULL){
            parent[root->right]=root;
            inorder(root->right);
        }
    }
    void BFS(TreeNode* target, int k, vector<int> &ans) {
        if(target==NULL){
            return;
        }
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while(!q.empty()){
            int n=q.size();

            if(k==0) break;
            while(n--){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left!=NULL && !visited.count(curr->left)){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right!=NULL && !visited.count(curr->right)){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if(parent.count(curr) && !visited.count(parent[curr])){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            k--;
        }

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
    }    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        inorder(root);
        BFS(target,k,ans);
        return ans;
        
    }
};