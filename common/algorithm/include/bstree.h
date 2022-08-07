/*
Copyright (C), 2020-2050, Tech. Co., Ltd.
File name: bstree.h
Author: Youjian zhang
Version: 1.0
Date: 2021.1.2
Description: heard file
*/
#ifndef BSTREE_H
#define BSTREE_H
#include "type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int type;

typedef struct BSTreeNode {
    type key;
    struct BSTreeNode *parent;
    struct BSTreeNode *left;
    struct BSTreeNode *right;
} Node, *BSTree;

typedef void (*BSTreeCallBack)(type key);

Node *BSTreeCreateNode(type key, Node *parent, Node *left, Node *right);

void BSTreeDestroy(BSTree root);

Node *BSTreeLookUp(BSTree root, type key);

BSTree BSTreeInsert(BSTree root, type key);

BSTree BSTreeDelete(BSTree root, type key);

void BSTreePreOrderVisit(const BSTree root, BSTreeCallBack func);

void BSTreeInOrderVisit(const BSTree root, BSTreeCallBack func);

void BSTreePostOrderVisit(const BSTree root, BSTreeCallBack func);

#ifdef __cplusplus
}
#endif
#endif
