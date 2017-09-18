/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize(TreeNode* root, ostringstream& oss) {
        if (!root) 
            oss<<"# "; //lc是用level order,更省空间？
        else {
            oss<<root->val<<" ";
            serialize(root->left, oss);
            serialize(root->right, oss);
        }
    }
    TreeNode* deserialize(istringstream &iss) {
        string val;
        iss>>val;
        if (val != "#") {
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserialize(iss);
            root->right = deserialize(iss);
            return root;
        }
        else 
            return NULL;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
How to store a general Binary Tree?
A simple solution is to store both Inorder and Preorder traversals. This solution requires requires space twice the size of Binary Tree.
We can save space by storing Preorder traversal and a marker for NULL pointers.

    
    // A C++ Program serialize and deserialize an N-ary tree
#include<cstdio>
#include <sstream>
#include <iostream>
#define MARKER ')'
#define N 5
using namespace std;
 
// A node of N-ary tree
struct Node {
   int key;
   Node *child[N];  // An array of pointers for N children
};
 
// A utility function to create a new N-ary tree node
Node *newNode(char key)
{
    Node *temp = new Node;
    temp->key = key;
    for (int i = 0; i < N; i++)
        temp->child[i] = NULL;
    return temp;
}
 
// This function stores the given N-ary tree in a file pointed by fp
void serialize(Node *root, ostringstream& oss)
{
    // Base case
    if (root == NULL) return;
 
    // Else, store current node and recur for its children
    //fprintf(fp, "%c ", root->key);
    oss<<root->key<<" ";
    for (int i = 0; i < N && root->child[i]; i++)
         serialize(root->child[i],  oss);
 
    oss<<"# ";
    // Store marker at the end of children
    //fprintf(fp, "%c ", MARKER);
}
 
// This function constructs N-ary tree from a file pointed by 'fp'.
// This functionr returns 0 to indicate that the next item is a valid
// tree key. Else returns 0
bool deSerialize(Node *&root, istringstream &iss)
{
    // Read next item from file. If theere are no more items or next
    // item is marker, then return 1 to indicate same
    string val;
    
    if ( !(iss>>val)|| val == "#")
       return false;
 
    // Else create node with this item and recur for children
    root = newNode(stoi(val));
    for (int i = 0; i < N; i++)
      if (!deSerialize(root->child[i], iss))
         break;
 
    // Finally return 0 for successful finish
    return true;
}
 
// A utility function to create a dummy tree shown in above diagram
Node *createDummyTree()
{
    Node *root = newNode(1);
    root->child[0] = newNode(2);
    root->child[1] = newNode(3);
    root->child[2] = newNode(4);
    root->child[0]->child[0] = newNode(5);
    root->child[0]->child[1] = newNode(6);
    root->child[2]->child[0] = newNode(7);
    root->child[2]->child[1] = newNode(8);
    root->child[2]->child[2] = newNode(9);
    root->child[2]->child[3] = newNode(10);
    root->child[0]->child[1]->child[0] = newNode(11);
    return root;
}
 
// A utlity function to traverse the constructed N-ary tree
void traverse(Node *root)
{
    if (root)
    {
        printf("%d ", root->key);
        for (int i = 0; i < N; i++)
            traverse(root->child[i]);
    }
}
 
// Driver program to test above functions
int main()
{
    // Let us create an N-ary tree shown in above diagram
    Node *root = createDummyTree();
 
    // Let us open a file and serialize the tree into the file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    

    ostringstream oss;
    serialize(root, oss);
    string input = oss.str();
    cout<<input<<endl;
    fclose(fp);
 
    // Let us deserialize the storeed tree into root1
    Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    istringstream iss(input);
    deSerialize(root1, iss);
 
    printf("Constructed N-Ary Tree from file is \n");
    traverse(root1);
 
    return 0;
}
