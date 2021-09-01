#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASK_NUMS      1001

typedef struct {
    int tastId;
    ENode *next;
} ENode;

typedef struct {
    ENode *firstNode;
} VNode;

typedef struct {
    int eNums;;
    int vNums;
    VNode node[MAX_TASK_NUMS];
} GraphT;


GraphT *CreateGraph(int taskNum, int *relations[2], int relationCnt)
{
    GraphT *graph = (GraphT *)malloc(sizeof(GraphT));
    memset(graph, 0, sizeof(GraphT));
    graph->vNums = taskNum;
    graph->eNums = relationCnt;
    for (int i = 1; i <= taskNum; ++i) {
        graph->node[i].firstNode = NULL;
    }

    for (int i = 0; i < relationCnt; ++i) {
        int begin = relations[i][0];
        int end = relations[i][1];
        if (graph->node[begin].firstNode == NULL) {
            graph->node[begin].firstNode = (ENode *)malloc(sizeof(ENode));
            graph->node[begin].firstNode->tastId = end;
            graph->node[begin].firstNode->next = NULL;
        } else {
            ENode *nextNode = graph->node[begin].firstNode;
            while(nextNode->next != NULL) {
                nextNode = nextNode->next;
            }
            nextNode->next = (ENode *)malloc(sizeof(ENode));
            nextNode->tastId = end;
            nextNode->next = NULL;
        }
    }
}

void DestroyGraph(GraphT *graph)
{
    for (int i = 1; i <= graph->vNums; ++i) {
        ENode *node = graph->node[i].firstNode;
        while(node != NULL) {
            ENode *next = node->next;
            free(node);
            node = next;
        }
    }

    free(graph);
}


int GetMinTime(int taskNum, int *relations[2], int relationCnt)
{

    GraphT *graph = CreateGraph(taskNum, relations, relationCnt);
    if (graph == NULL) {
        return -1;
    }
    int front = 0;
    int tail = 0;
    int index = 0;
    int *queue = (int *)malloc(sizeof(int) * (taskNum + 1));
    if (queue == NULL) {
        return -1;
    }
    memset(queue, 0, sizeof(int) * (taskNum + 1));

    int *tops = (int *)malloc(sizeof(int) * (taskNum + 1));
    if (tops == NULL) {
        return -1;
    }
    memset(tops, 0, sizeof(int) * (taskNum + 1));
    
    int *ins = (int *)malloc(sizeof(int) * (taskNum + 1));
    if (ins == NULL) {
        return -1;
    }

    memset(ins, 0, sizeof(int) * (taskNum + 1));

    for (int i = 1; i <= taskNum; ++i) {
        ENode *node = graph->node[i].firstNode;
        while(node != NULL) {
            ins[node->tastId]++;
            node = node->next;
        }
    }

    for (int i = 1; i <= taskNum; ++i) {
        if (ins[i] ==0) {
            queue[tail++] = i;
        }
    }

    while(front != tail) {
        int taskId = queue[front++];
        tops[index++] = taskId;

        ENode *node = graph->node[taskId].firstNode;
        while(node != NULL) {
            ins[node->tastId]--;
            if (ins[node->tastId] == 0) {
                queue[tail++] = node->tastId;
            }
            node = node->next;
        }


    }


    DestroyGraph(graph);
}

int main(int argc, char *argv[])
{
    printf("hello World\n");
    return 0;
}