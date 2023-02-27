#include<iostream>
#include<queue>
using namespace std;
inline int Max(int a,int b)
{
    return a>b?a:b;
}
typedef struct TreeNode //定义
{
    int data;
    TreeNode* left;
    TreeNode* right;
}*Tree;
TreeNode* GetNewNode(int data) //获取新结点
{
    TreeNode *q = new TreeNode();
    q->data = data;
    q->left = NULL;
    q->right = NULL;
    return q;
}
void Insert(Tree &root,int data) //插入新元素
{
    if(root==NULL)
    {
        root = GetNewNode(data);
        // cout << root->data;
    }
    else if(data <= root->data) Insert(root->left, data);
    else if(data > root->data) Insert(root->right, data);
}
void Inorder(Tree T) //中序遍历
{
    if(T!=NULL)
    {
        Inorder(T->left);
        cout<< T->data <<endl;
        Inorder(T->right);
    }
}
void Search(Tree &T,int data) //搜索
{
    if(T==NULL){
        throw "Value Not Found";
    }
    if(T->data == data){
        cout << "Found";
    }
    else if(data <= T->data) Search(T->left,data);
    else if(data > T->data) Search(T->right,data);
}
TreeNode* FindMax(Tree T) //找最大值
{
    TreeNode *current = T;
    if(current==NULL) cout << "Empty" <<endl;
    else if(current->right==NULL) return current;
    return FindMax(current->right);
}
TreeNode* FindMin(Tree T) //找最小值
{
    TreeNode *current = T;
    if(current==NULL) cout << "Empty" <<endl;
    else if(current->left == NULL){
        return current;
    }
    else FindMin(current->left);
}
int Height(Tree T) //求高度
{
    if(T==NULL) return -1;
    int LeftHeight = Height(T->left);
    int RightHeight = Height(T->right);
    return Max(LeftHeight,RightHeight)+1;
}
void LevelOrder(Tree T) //层序遍历
{
    queue<TreeNode*> Q;
    Q.push(T);
    while(!Q.empty())
    {
        TreeNode* top = Q.front();
        cout << top->data <<endl;
        if(top->left !=NULL) Q.push(top->left);
        if(top->right != NULL) Q.push(top->right);
        Q.pop();
    }
}
void Delete(Tree &T,int data) //删除一个结点
{
    if(T==NULL) cout << "Empty" << endl;
    cout << T->data << endl;
    if(data < T->data)
    {
        Delete(T->left,data);
    }
    else if(data >T->data)
    {
        Delete(T->right,data);
    }
    else
    {
        if(T->left == NULL && T->right == NULL)
        {
            delete T;
            // cout << T->data <<" deleted.(1)" <<endl;
            // T = NULL;
        }
        else if(T->left == NULL)
        {
            TreeNode *temp = T;
            // cout << temp->data <<" deleted.(2)" <<endl;
            T = T->right;
            // temp = NULL;
            delete temp;
        }
        else if(T->right ==NULL)
        {
            TreeNode *temp =T;
            // cout << temp->data <<" deleted.(3)" <<endl;
            T = T->left;
            // temp = NULL;
            delete temp;
        }
        else
        {
            TreeNode *temp = FindMin(T->right); 
            T->data = temp->data;
            Delete(T->right,temp->data);
        }
    }

}

int main()
{   
    Tree T = NULL;
    Insert(T,3);
    Insert(T,2);
    Insert(T,5);
    LevelOrder(T);
    return 0;
}
