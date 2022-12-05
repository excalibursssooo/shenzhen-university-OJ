#include <bits/stdc++.h>
using namespace std;
class BiTreeNode {
public:
    char data;                                   //数据域
    BiTreeNode *leftChild, *rightChild, *father; //左右子树指针
    BiTreeNode() :
        leftChild(NULL), rightChild(NULL), father(NULL) {
    }
    ~BiTreeNode() {
    }
};

class BiTree {
private:
    int maxi;
    BiTreeNode *root;                      //根结点指针
    string sTree;                          //建树字符串
    int pos;                               //标识建树字符串的当前字符位置
    BiTreeNode *CreateTree(BiTreeNode *t); //建树私有函数
    void PreOrder(BiTreeNode *t);          //先序遍历实现
    void InOrder(BiTreeNode *t);           //中序遍历实现
    void PostOrder(BiTreeNode *t);         //后序遍历实现
    void LevelOrder(BiTreeNode *t);        //层序遍历实现
    BiTreeNode *pi;
    int num;
    char father[1001];
    char kids[1001];
    void showfather();
    void showkids();
    void showdeep();
    int deep = 0;
    int maxdeep = 0;
    int longest(BiTreeNode *t);
    void findlong(BiTreeNode *t);
    char c1, c2;
    void Level(BiTreeNode *t);

public:
    BiTree() :
        root(NULL){};
    void Create(string vArray); //建树公有接口，参数是特定的先序遍历字符串
    void PreOrder();            //先序遍历公有接口
    void InOrder();             //中序遍历公有接口
    void PostOrder();           //后序遍历公有接口
    void LevelOrder();
    int cnt = 0;
    void showf();
    void showk();
    void showd();
    int longest();
    void findlong();
};
//二叉树公有接口的实现
void BiTree::findlong() {
    pi = NULL;
    maxi = 0;
    findlong(root);
    cout << maxi << ":";
    if (pi == NULL)
        cout << endl;
    else {
        Level(pi->leftChild);
        cout << " ";
        Level(pi->rightChild);
        cout << endl;
    }
}
void BiTree::Create(string vArray) {
    pos = 0;
    num = 0;
    sTree.assign(vArray);    //把参数保存到内部字符串
    root = CreateTree(root); //建树成功后root指向根结点
}
void BiTree::PreOrder() {
    PreOrder(root);
}
void BiTree::InOrder() {
    InOrder(root);
}
void BiTree::PostOrder() {
    PostOrder(root);
}
void BiTree::LevelOrder() {
    LevelOrder(root);
}
void BiTree::showf() {
    showfather();
}
void BiTree::showk() {
    showkids();
}
void BiTree::showd() {
    showdeep();
}
//请完成上述类内部的私有函数实现
/********** Write your code here! **********/
BiTreeNode *BiTree::CreateTree(BiTreeNode *t) {
    BiTreeNode *p = new BiTreeNode;
    p->father = t;
    if (sTree[pos] == '0') {
        p = NULL;
        pos++;
    } else {
        p->data = sTree[pos];
        pos++;
        p->leftChild = CreateTree(p);
        p->rightChild = CreateTree(p);
    }
    if (p != NULL) {
        if (p->leftChild == NULL && p->rightChild == NULL && p->father != NULL) {
            father[num] = p->father->data;
            kids[num] = p->data;
            num++;
        }
    }
    return p;
}

void BiTree::PreOrder(BiTreeNode *t) {
    if (t) {
        cout << t->data;
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);
    }
}
void BiTree::InOrder(BiTreeNode *t) {
    if (t) {
        InOrder(t->leftChild);
        cout << t->data;
        InOrder(t->rightChild);
    }
}
void BiTree::PostOrder(BiTreeNode *t) {
    if (t) {
        PostOrder(t->leftChild);
        PostOrder(t->rightChild);
        cout << t->data;
    }
}

void BiTree::showfather() {
    for (int i = 0; i < num; i++) {
        cout << father[i] << " ";
    }
}

void BiTree::showkids() {
    for (int i = 0; i < num; i++) {
        cout << kids[i] << " ";
    }
}
void BiTree::showdeep() {
    cout << maxdeep << endl;
}
void BiTree::LevelOrder(BiTreeNode *t) {
    queue<BiTreeNode *> q;
    q.push(t);
    while (!q.empty()) {
        BiTreeNode *p = new BiTreeNode;
        p = q.front();
        q.pop();
        if (p != NULL) {
            cout << p->data;
            q.push(p->leftChild);
            q.push(p->rightChild);
        }
    }
}
void BiTree::Level(BiTreeNode *t) {
    queue<BiTreeNode *> q;
    q.push(t);
    while (!q.empty()) {
        BiTreeNode *p = new BiTreeNode;
        p = q.front();
        q.pop();
        if (p != NULL) {
            if (p->leftChild != NULL) q.push(p->leftChild);
            if (p->rightChild != NULL) q.push(p->rightChild);
        }
        if (q.empty()) cout << p->data;
    }
}
int BiTree::longest(BiTreeNode *t) {
    if (t == NULL)
        return 0;
    else
        return max(longest(t->leftChild), longest(t->rightChild)) + 1;
}
int BiTree::longest() {
    return longest(root);
}
void BiTree::findlong(BiTreeNode *t) {
    if (t) {
        if (longest(t->leftChild) + longest(t->rightChild) > maxi) {
            maxi = longest(t->leftChild) + longest(t->rightChild);
            pi = t;
        }
        findlong(t->leftChild);
        findlong(t->rightChild);
    }
}
/*******************************************/
//主函数
int main() {
    int t;
    string vArray;

    cin >> t;
    while (t--) {
        cin >> vArray;
        BiTree myTree;
        myTree.Create(vArray);
        myTree.findlong();
    }
    return 0;
}
