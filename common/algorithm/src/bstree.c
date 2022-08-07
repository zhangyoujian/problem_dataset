#include "bstree.h"
#include "pub.h"

#ifdef __cplusplus
extern "C" {
#endif

Node *BSTreeCreateNode(type key, Node *parent, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return node;
    }
    node->key = key;
    node->parent = parent;
    node->left = left;
    node->right = right;
    return node;
}

void BSTreeDestroy(BSTree root)
{
    if (root == NULL) {
        return;
    }
    BSTreeDestroy(root->left);
    BSTreeDestroy(root->right);
    free(root);
}

Node *BSTreeLookUp(BSTree root, type key)
{
    Node *curNode = root;
    while(curNode) {
        if (curNode->key == key) {
            return curNode;
        } else if (curNode->key <key) {
            curNode = curNode->right;
        } else {
            curNode = curNode->left;
        }
    }
    return NULL;
}

BSTree BSTreeInsert(BSTree root, type key)
{
    if (root == NULL) {
        return root;
    }
    Node *curNode = root;
    Node *parent = root->parent;
    while(curNode) {
        parent = curNode;
        if (curNode->key == key) { // 不允许插入相同的key
            return NULL;
        } else if (curNode->key <key) {
            curNode = curNode->right;
        } else {
            curNode = curNode->left;
        }
    }
    Node *newNode = BSTreeCreateNode(key, parent, NULL, NULL);
    if (newNode == NULL) {
        return NULL;
    }
    if (parent == NULL) {
        return newNode;
    } else if (parent->key < key) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
    return root;
}

static Node *BSTreeSearchMin(BSTree root)
{
    if (root == NULL) {
        return NULL;
    }
    Node *curNode = root;
    while(curNode->left != NULL) {
        curNode = curNode->left;
    }
    return curNode;
}

static Node *BSTreeSearchMax(BSTree root)
{
    if (root == NULL) {
        return NULL;
    }
    Node *curNode = root;
    while(curNode->right != NULL) {
        curNode = curNode->right;
    }
    return curNode;
}

static Node *BSTreeSearchPrev(BSTree root)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->left != NULL) {
        return BSTreeSearchMax(root->left);
    }
    Node *parent = root->parent;
    Node *curNode = root;
    while(parent != NULL && parent->left == curNode) {
        curNode = parent;
        parent = curNode->parent;
    }
    return parent;
}

static Node *BSTreeSearchNext(BSTree root)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->right != NULL) {
        return BSTreeSearchMin(root->right);
    }
    Node *parent = root->parent;
    Node *curNode = root;
    while(parent != NULL && parent->right == curNode) {
        curNode = parent;
        parent = curNode->parent;
    }
    return parent;
}

BSTree BSTreeDelete(BSTree root, type key)
{
    Node *delete = BSTreeLookUp(root, key);
    if (delete == NULL) {
        return NULL;
    }
    Node *swapNode = NULL;
    if (delete->left == NULL || delete->right == NULL) {
        swapNode = delete;
    } else {
        swapNode = BSTreeSearchNext(delete);
    }
    if (swapNode != delete) {
        type tmp = swapNode->key;
        swapNode->key = delete->key;
        delete->key = tmp;
    }
    // 将原本要删除delete节点改为要删除swapNode节点
    Node *parent = swapNode->parent;
    // 修改待删除节点孩子节点的指向
    Node *child = swapNode->left == NULL ? swapNode->right : swapNode->left;
    if (child != NULL) {
        child->parent = parent;
    }
    // 修改待删除节点父亲节点的指向
    if (parent != NULL && parent->left == swapNode) {
        parent->left = child;
    } else if (parent != NULL && parent->right == swapNode) {
        parent->right = child;
    }
    free(swapNode);
    // 如果待删除节点为根节点
    if (parent == NULL) {
        return child;
    }
    return root;
}

void BSTreePreOrderVisit(const BSTree root, BSTreeCallBack func)
{
    if (root == NULL) {
        return;
    }
    func(root->key);
    BSTreePreOrderVisit(root->left, func);
    BSTreePreOrderVisit(root->right, func);
}

void BSTreeInOrderVisit(const BSTree root, BSTreeCallBack func)
{
    if (root == NULL) {
        return;
    }
    BSTreeInOrderVisit(root->left, func);
    func(root->key);
    BSTreeInOrderVisit(root->right, func);
}

void BSTreePostOrderVisit(const BSTree root, BSTreeCallBack func)
{
    if (root == NULL) {
        return;
    }
    BSTreePostOrderVisit(root->left, func);
    BSTreePostOrderVisit(root->right, func);
    func(root->key);
}


#ifdef __cplusplus
}
#endif