//Top view of Tree
//HackerRank
#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
 
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        if(root==NULL)
            return;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node *node=it.first;
            int line=it.second;
            if(mpp.find(line)==mpp.end())
                mpp[line]=node->data;
            if(node->left!=NULL)
                q.push({node->left,line-1});
            if(node->right!=NULL)
                q.push({node->right,line+1});
            
        }
        for(auto it:mpp)
            cout<<it.second<<" ";

    }

}; //End of Solution

