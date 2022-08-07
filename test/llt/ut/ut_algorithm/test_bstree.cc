#include <iostream>
#include "gtest/gtest.h"
#include <algorithm>
#include <vector>
#include "pub.h"
using namespace std;
#include "bstree.h"

void BSTreeProcess(type key)
{
    printf("%d ", key);
}

class test_bstree : public testing::Test {
protected:

    static void SetUpTestCase() {
        std::cout<< "TEST_F begin"<<std::endl;
    }

    static void TearDownTestCase() {
    }

    virtual void SetUp() {

    /*
                         7
                       /  \
                      4   15
                    /  \ /  \
                    1  6 10   35
                           \  /
                           13 27


    */
        root = BSTreeCreateNode(7, NULL, NULL, NULL);
        ASSERT_NE(BSTreeInsert(root, 4), nullptr);
        ASSERT_NE(BSTreeInsert(root, 15), nullptr);
        ASSERT_NE(BSTreeInsert(root, 1), nullptr);
        ASSERT_NE(BSTreeInsert(root, 6), nullptr);

        ASSERT_NE(BSTreeInsert(root, 10), nullptr);
        ASSERT_NE(BSTreeInsert(root, 35), nullptr);
        ASSERT_NE( BSTreeInsert(root, 13), nullptr);

        ASSERT_NE(BSTreeInsert(root, 27), nullptr);
        // 插入重复key失败，返回nullptr
        ASSERT_EQ(BSTreeInsert(root, 27), nullptr);

        printf("preorder visit: ");
        BSTreePreOrderVisit(root, BSTreeProcess);
        printf("\n");
        printf("inorder visit: ");
        BSTreeInOrderVisit(root, BSTreeProcess);
        printf("\n");
        printf("postOrder visit: ");
        BSTreePostOrderVisit(root, BSTreeProcess);
        printf("\n");

    }
    virtual void TearDown() {
        BSTreeDestroy(root);
    }
public:
    Node *root = NULL;
};

TEST_F(test_bstree, test_delete_1)
{
    type data = 1;
    Node *node = BSTreeLookUp(root, data);
    if (node == NULL) {
        ASSERT_EQ(-1, 0);
    }

    // 开始删除节点
    ASSERT_NE(BSTreeDelete(root, data), nullptr);
    printf("inorder visit: ");
    BSTreeInOrderVisit(root, BSTreeProcess);

    printf("\n");
    ASSERT_EQ(BSTreeLookUp(root, data), nullptr);
}

TEST_F(test_bstree, test_delete_13)
{
    type data = 13;
    Node *node = BSTreeLookUp(root, data);
    if (node == NULL) {
        ASSERT_EQ(-1, 0);
    }

    // 开始删除节点
    ASSERT_NE(BSTreeDelete(root, data), nullptr);
    printf("inorder visit: ");
    BSTreeInOrderVisit(root, BSTreeProcess);
    
    printf("\n");
    ASSERT_EQ(BSTreeLookUp(root, data), nullptr);
}

TEST_F(test_bstree, test_delete_10)
{
    type data = 10;
    Node *node = BSTreeLookUp(root, data);
    if (node == NULL) {
        ASSERT_EQ(-1, 0);
    }

    // 开始删除节点
    ASSERT_NE(BSTreeDelete(root, data), nullptr);
    printf("inorder visit: ");
    BSTreeInOrderVisit(root, BSTreeProcess);
    
    printf("\n");
    ASSERT_EQ(BSTreeLookUp(root, data), nullptr);
}

TEST_F(test_bstree, test_delete_35)
{
    type data = 35;
    Node *node = BSTreeLookUp(root, data);
    if (node == NULL) {
        ASSERT_EQ(-1, 0);
    }

    // 开始删除节点
    ASSERT_NE(BSTreeDelete(root, data), nullptr);
    printf("inorder visit: ");
    BSTreeInOrderVisit(root, BSTreeProcess);
    
    printf("\n");
    ASSERT_EQ(BSTreeLookUp(root, data), nullptr);
}

TEST_F(test_bstree, test_delete_15)
{
    type data = 15;
    Node *node = BSTreeLookUp(root, data);
    if (node == NULL) {
        ASSERT_EQ(-1, 0);
    }

    // 开始删除节点
    ASSERT_NE(BSTreeDelete(root, data), nullptr);
    printf("inorder visit: ");
    BSTreeInOrderVisit(root, BSTreeProcess);
    
    printf("\n");
    ASSERT_EQ(BSTreeLookUp(root, data), nullptr);
}

TEST_F(test_bstree, test_delete_7)
{
    type data = 7;
    Node *node = BSTreeLookUp(root, data);
    if (node == NULL) {
        ASSERT_EQ(-1, 0);
    }

    // 开始删除节点
    ASSERT_NE(BSTreeDelete(root, data), nullptr);
    printf("inorder visit: ");
    BSTreeInOrderVisit(root, BSTreeProcess);
    printf("\n");
    printf("Preorder visit: ");
    BSTreePreOrderVisit(root, BSTreeProcess);
    printf("\n");
    printf("postOrder visit: ");
    BSTreePostOrderVisit(root, BSTreeProcess);
    printf("\n");

    ASSERT_EQ(BSTreeLookUp(root, data), nullptr);
}

TEST_F(test_bstree, deleteBSTree)
{
    BSTreeInOrderVisit(root, BSTreeProcess);
    printf("\n");

    // 开始删除节点
    ASSERT_NE(BSTreeDelete(root, 7), nullptr);
    ASSERT_EQ(BSTreeLookUp(root, 7), nullptr);

    BSTreePostOrderVisit(root, BSTreeProcess);
    printf("\n");
}
