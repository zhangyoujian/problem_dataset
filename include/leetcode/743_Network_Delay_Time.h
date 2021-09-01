#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NODE_NUMS       101
#define INF                 0XFF

typedef struct TagGraphT {
   char vnode[MAX_NODE_NUMS];
   int  vCnt;
   unsigned char dist[MAX_NODE_NUMS][MAX_NODE_NUMS];
} GraphT;

void InitGraph(int** times, int timesSize, int* timesColSize, int n, GraphT *graph)
{
    graph->vCnt = n;
    memset(graph->vnode, 0, sizeof(graph->vnode));
    memset(graph->dist, INF, sizeof(graph->dist));
    for (int i = 0; i < timesSize; ++i) {
        int *time = times[i];
        graph->vnode[time[0]] = 1;
        graph->vnode[time[1]] = 1;
        graph->dist[time[0]][time[0]] = 0;
        graph->dist[time[1]][time[1]] = 0;
        graph->dist[time[0]][time[1]] = time[2];
    }
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    unsigned char dist[MAX_NODE_NUMS] = {0};
    unsigned char visited[MAX_NODE_NUMS] = {0};
    GraphT graph;
    InitGraph(times, timesSize, timesColSize, n, &graph);
    
    for (int i = 1; i <= n; ++i) {
        dist[i] = graph.dist[k][i];
    }

    dist[k]    = 0;
    visited[k] = 1;

    for (int i = 1; i <= n; ++i) {
        unsigned char minDist = INF;
        int index = -1;
        for (int j = 1; j <= n; ++j) {
            if (graph.vnode[j] == 0 || visited[j] == 1) {
                continue;
            }
            if (dist[j] < minDist) {
                minDist = dist[j];
                index = j;
            }
        }

        if (index == -1) {
            continue;
        }

        dist[index] = minDist;
        visited[index] = 1;
        for (int j = 1; j <= n; ++j) {
            if (graph.vnode[j] == 0 || visited[j] == 1) {
                continue;
            }
            int tmpDist = minDist + graph.dist[index][j];
            if (tmpDist < dist[j]) {
                dist[j] = tmpDist;
            }
        }
    }
    
    unsigned char maxDist = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
        }
    }
    return maxDist == INF ? -1 : maxDist;
}