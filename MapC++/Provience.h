//
//  Provience.h
//  Map
//
//  Created by 阴浩 on 20/01/2017.
//  Copyright © 2017 yhMaruriYin. All rights reserved.
//

#ifndef Provience_h
#define Provience_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//相邻省份节点信息
typedef struct NearbyPro{

    int seq;
    float distance;
    struct NearbyPro *next;


}NearbyPro;

//省份节点信息
typedef struct Provience{

    char name[50];
    char captail[50];
    char num[5];//区号
    double popultion;
    int sesquence;
    int nears;

    int color;

    struct Provience *next;
    NearbyPro *near;

}Provience;

//图的定义
typedef struct
{
    int vertexNum;//图的顶点个数
    int edgeNum;//图的边的数目
    int vertex[100];//图中顶点的内容
    int arc[100][100];//图中顶点间的连通性
}Graph,*PGraph;

//辅助数组元素
typedef struct
{
    int from;
    int to;
    int weight;
    int flag;
}ArrayNode;
//从文件中读取各个省份的信息，以邻接表的形式储存
int LoadFromDoc(Provience *&head);
void LoadNears(Provience *&head, int num);

//根据邻接表信息创建矩阵解决图着色及最小生成树的问题
void CreateMatrix(Provience *&head);
void CreateNet();

bool ColorIsRight(int k,int c[][35]);
void graphcolor(int n, int m, int c[][35], Provience *&head, int num);
void Scripts(Provience *p);

void createdGraph(PGraph g, Provience *head);
void initTree(PGraph tree);
void prim(PGraph g,PGraph tree);
#endif /* Provience_h */
