#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//     1
//    / \
    //   2   3
//  / \ / \
    // 4   56  7
void preorderprint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}
void inorderprint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}
void postorderprint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderprint(root->left);
    postorderprint(root->right);
    cout << root->data << " ";
}
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
node *buildtreepre(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node *newnode = new node(curr);
    if (start == end)
    {
        return newnode;
    }
    int pos = search(inorder, start, end, curr);
    newnode->left = buildtreepre(preorder, inorder, start, pos - 1);
    newnode->right = buildtreepre(preorder, inorder, pos + 1, end);
    return newnode;
}
node *buildtreepost(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    node *newnode = new node(val);
    if (start == end)
    {
        return newnode;
    }

    int pos = search(inorder, start, end, val);
    newnode->right = buildtreepost(postorder, inorder, pos + 1, end);
    newnode->left = buildtreepost(postorder, inorder, start, pos - 1);
    return newnode;
}
void printlevelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
int sumatklevel(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0, sum = 0;
    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
int totalnodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return totalnodes(root->left) + totalnodes(root->right) + 1;
}
int totalsum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return totalsum(root->left) + totalsum(root->right) + root->data;
}
int calcHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    return max(lheight, rheight) + 1;
}
int calcDiameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    int currdiameter = lheight + rheight + 1;
    int ldiameter = calcDiameter(root->left);
    int rdiameter = calcDiameter(root->right);
    return max(currdiameter, max(lheight, rheight));
}
int diameter(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = diameter(root->left, &lh);
    int rdiameter = diameter(root->right, &rh);

    int currdiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currdiameter, max(ldiameter, rdiameter));
}
void sumReplace(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}
bool isbalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isbalanced(root->left) == false)
    {
        return false;
    }
    if (isbalanced(root->right) == false)
    {
        return false;
    }
    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);
    if (abs(lh - rh) <= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool balanced(node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (balanced(root->left, &lh) == false)
    {
        return false;
    }
    if (balanced(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void rightview(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop();
            if (i == n - 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}
void leftview(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (i == 0)
            {
                cout << temp->data << " ";
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
node *LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findst(node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }
    int left = findst(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return findst(root->right, k, dist + 1);
}
int distbtwnodes(node *root, int n1, int n2)
{
    node *lca = LCA(root, n1, n2);
    int d1 = findst(lca, n1, 0);
    int d2 = findst(lca, n2, 0);
    return d1 + d2;
}
void flatten(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}
//case 1
void printSubtreenodes(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printSubtreenodes(root->left, k - 1);
    printSubtreenodes(root->right, k - 1);
}
// case 2
int printnodesatk(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubtreenodes(root, k);
        return 0;
    }
    int dl = printnodesatk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreenodes(root->right, k - dl - 2);
        }
        return dl + 1;
    }
    int dr = printnodesatk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreenodes(root->left, k - dr - 2);
        }
        return dr + 1;
    }
    return -1;
}
bool getPath(node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
int LowCA(node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc - 1];
}
int maxPathSumUtil(node *root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left = maxPathSumUtil(root->left,ans);
    int right = maxPathSumUtil(root->right,ans);

    int nodemax = max(max(root->data,root->data+left+right),max(root->data + left,root->data+right));

    ans = max(ans,nodemax);
    int singlepathsum = max(root->data,max(root->data+left,root->data + right));

    return singlepathsum;
}
int maxPathSum(node *root){
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}
int main()
{
    node *root = new node(1);
    root->left = new node(-12);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(-6);
    //  root->right->right->right = new node(30);
    cout<<maxPathSum(root)<<endl;
    // int n1 = 7, n2 = 6;
    // cout << LowCA(root, n1, n2) << endl;
    //printnodesatk(root, root->left, 1);
    // root->left->right = new node(3);
    // root->right->right = new node(6);
    // flatten(root);
    // inorderprint(root);
    // cout << endl;
    // root->right->left=new node(6);
    // root->right->right=new node(7);
    // cout<<distbtwnodes(root,4,5)<<endl;
    int height = 0;
    // rightview(root);
    // cout<<endl;
    // leftview(root);
    // root->right->right->right=new node(100);
    // root->right->right->right->right=new node(200);
    // cout<<balanced(root,&height)<<endl;
    // preorderprint(root);cout<<endl;
    // sumReplace(root);cout<<endl;
    // preorderprint(root);cout<<endl;
    // cout<<calcHeight(root)<<endl;
    // cout<<calcDiameter(root)<<endl;
    // cout<<diameter(root,&height)<<endl;
    // printlevelorder(root);cout<<endl;
    // int ans=sumatklevel(root,2);
    // cout<<ans<<endl;
    // cout<<totalnodes(root)<<endl;
    // cout<<totalsum(root)<<endl;
    // preorder(root);cout<<endl;
    // inorder(root);cout<<endl;
    // postorder(root);
    // int preorder[]={1,2,4,3,5};
    // int postorder[]={4,2,5,3,1};
    // int inorder[]={4,2,1,5,3};
    // node *newroot = buildtreepre(preorder,inorder,0,4);
    // inorderprint(newroot);
    // node *newroot1=buildtreepost(postorder,inorder,0,4);
    // postorderprint(newroot1);
    return 0;
}