// implementation of bst and its functions

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class bst
{
    
    public:
    node *root;
    bst()
    {
        root = NULL;
    }
    // visit
    // height
    // ancestors
    // what level am i

    void insert(int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void printGivenLevel(node *, int);
    void levelorder(node *);
    void visit(node *);
    int height(node *);
    void ancestors(node *, int);
    int whatlevelamI(node *, int, int);

};

void bst::insert(int x)
{
    node *t = new node;
    node *parent;
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;

    // is this a new tree?
    if (root == NULL)
    {
        root = t;
    }
    else
    {
        // Note: ALL insertions are as leaf nodes
        node *curr;
        curr = root;
        // Find the Node's parent
        while (curr)
        {
            parent = curr;
            if (t->data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if (t->data < parent->data)
            parent->left = t;
        else
            parent->right = t;
    }
}

void bst::inorder(node *p)
{
    if (p != NULL)
    {
        if (p->left)
            inorder(p->left);
        visit(p);
        if (p->right)
            inorder(p->right);
    }
    else
        return;
}

void bst::preorder(node *p)
{
    if (p != NULL)
    {
        visit(p);
        if (p->left)
            preorder(p->left);
        if (p->right)
            preorder(p->right);
    }
    else
        return;
}

void bst::postorder(node *p)
{
    if (p != NULL)
    {
        if (p->left)
            postorder(p->left);
        if (p->right)
            postorder(p->right);
        visit(p);
    }
    else
        return;
}

void bst::levelorder(node *p)
{
    int h = height(p);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(p, i);
}

void bst::printGivenLevel(node *p, int level)
{
    if (p == NULL)
        return;
    if (level == 1)
        cout << p->data << " ";
    else if (level > 1)
    {
        printGivenLevel(p->left, level-1);
        printGivenLevel(p->right, level-1);
    }
}

void bst::visit(node *p)
{
    cout << p->data << " ";
}

int bst::height(node *p)
{
    int x=0, y=0;
    if (p == 0)
        return 0;
    x = height(p->left);
    y = height(p->right);
    if (x > y)
        return x+1;
    else
        return y+1;
}

void bst::ancestors(node *p, int key)
{
    if (p != NULL)
    {
        if (p->data == key)
            return;
        cout << p->data << " ";
        if (key < p->data)
            ancestors(p->left, key);
        if (key > p->data)
            ancestors(p->right, key);
    }
}

int bst::whatlevelamI(node *p, int key, int level)
{
    if (p == NULL)
        return 0;
    if (p->data == key)
        return level;
    int downlevel = whatlevelamI(p->left, key, level+1);
    if (downlevel != 0)
        return downlevel;
    downlevel = whatlevelamI(p->right, key, level+1);
    return downlevel;
}

int main()
{
    bst b;
    b.insert(50);
    b.insert(30);
    b.insert(20);
    b.insert(40);
    b.insert(70);
    b.insert(60);
    b.insert(80);

    cout << "Inorder: ";
    b.inorder(b.root);
    cout << endl;

    cout << "Preorder: ";
    b.preorder(b.root);
    cout << endl;

    cout << "Postorder: ";
    b.postorder(b.root);
    cout << endl;

    cout << "Levelorder: ";
    b.levelorder(b.root);
    cout << endl;

    cout << "Height: " << b.height(b.root) << endl;

    cout << "Ancestors of 40: ";
    b.ancestors(b.root, 40);
    cout << endl;

    cout << "Level of 40: " << b.whatlevelamI(b.root, 40, 1) << endl;

    return 0;
}

