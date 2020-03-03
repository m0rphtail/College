#include<iostream>
using namespace std;

class treeNode
{
    public:
    int data;
    treeNode *left,*right;
    public:
    treeNode()
    {
        left=NULL;
        right=NULL;
    }
};

class tree
{
    treeNode *root;
    void destroy(treeNode*);
    void pre_disp(treeNode*);
    void in_disp(treeNode*);
    void post_disp(treeNode*);
    treeNode* copy(treeNode*);
    public:
    void insert(int);
    void create(void);
    void pre_disp();
    void in_disp();
    void post_disp();
    int search(int);

}