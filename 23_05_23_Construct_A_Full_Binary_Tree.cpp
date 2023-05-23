/*Given two arrays that represent Preorder traversals of a Full binary tree preOrder[] and its mirror tree preOrderMirror[], your task is to complete the function constructBinaryTree(), that constructs the full binary tree using these two Preorder traversals.

Note: It is not possible to construct a general binary tree using these two traversal. But it is possible to create a full binary tree using the above traversals without any ambiguity.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/

class Solution{
  public:
    Node* merge(int ar1[], int ar2[], int s1, int e1, int s2, int e2)
    {
        struct Node* node = new Node(ar1[s1]);
        
        if(s1 == e1)
        {
            return node;
        }
        
        int temp1 = ar1[s1+1];
        int temp2 = ar2[s2+1];
        
        int ptr1 = 0, ptr2 = 0;
        
        for(int i = s2 + 1; i<= e2; i++)
        {
            if(ar2[i] == temp1)
            {
                ptr2 = i;
                break;
            }
        }
        for(int i = s1 + 1; i<= e1; i++)
        {
            if(ar1[i] == temp2)
            {
                ptr1 = i;
                break;
            }
        }
        node->left = merge(ar1, ar2, s1 + 1, ptr1-1, ptr2, e2);
        node->right = merge(ar1, ar2, ptr1, e1, s2 + 1, ptr2-1);
        return node;
    }
    
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        if(size == 0) return NULL;
        int s1 = 0, s2 = 0, e1 = size-1, e2 = size -1;
        struct Node* head = merge(pre, preMirror, s1, e1, s2, e2);
        return head;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
