//
//  Provience.c
//  Map
//
//  Created by 阴浩 on 20/01/2017.
//  Copyright © 2017 yhMaruriYin. All rights reserved.
//

#include "Provience.h"
#define MAX_VERTEX_NUM 100



//参数：传入头节点指针
//返回值：返回节点个数
//功能：根据文件读入节点信息
int LoadFromDoc(Provience *&head){
    FILE *fp = fopen("text.txt","r");

    if(!fp){
        printf("no documents!\n");
        return 0;
    }

    Provience *p = head;
    int i = 0;
    while (!feof(fp)) {
        i++;
        Provience *q = (Provience*)malloc(sizeof(Provience));
        q->sesquence = i;
        fscanf(fp,"%s%s%s%lf%d", q->name, q->captail, q->num, &q->popultion, &q->nears);
        q->color = 0;
        //        printf("%s %s %s %lf\n", q->name, q->captail, q->num, q->popultion);
        p->next = q;
        p = q;
    }
    fclose(fp);
    return i;
}


//参数：传入头节点指针及节点个数
//功能：根据文件信息建立边的关系
void LoadNears(Provience *&head, int num){
    Provience *p = head->next;
    FILE *fp = fopen("near.txt","r");

    if(!fp){
        printf("no documents!\n");
        return;
    }

    int i;
    for (i = 0; i < num; i++) {
        int k;
        int j = p->nears;
        p->near = (NearbyPro*)malloc(sizeof(NearbyPro));
        fscanf(fp,"%d%f", &p->near->seq, &p->near->distance);
        NearbyPro *np = p->near;
        for (k = 1; k < j; k++) {
            NearbyPro *q = (NearbyPro*)malloc(sizeof(NearbyPro));
            fscanf(fp,"%d%f", &q->seq, &q->distance);
            np->next = q;
            np = q;
        }
        p = p->next;
    }
    fclose(fp);
}


void CreateMatrix(Provience *&head){
    int a[35][35] = {0};
    Provience *p = head->next;
    while (p) {
        int i = p->nears;
        int j, m = p->sesquence;
        NearbyPro *q = p->near;
        for (j = 0; j < i; j++) {
            int n = q->seq;
            a[m][n] = 1;
            q = q->next;
        }
        p = p->next;
    }
    for (int x = 1; x <= 34; x++) {
        for (int y = 1; y <= 34; y++) {
            printf("%d ", a[x][y]);
        }
        printf("\n");
    }
}

int colors[100];
bool ColorIsRight(int k,int c[][35])//判断顶点k的着色是否发生冲突
{
    int i;
    for(i = 1; i < k; i++){
        if(c[k][i]==1 && colors[i]==colors[k])
            return false;
    }
    return true;
}

void graphcolor(int n, int m, int c[][35], Provience *&head){
    Provience *p = head->next;
    int count = 1;

    while (p) {
        int i = p->nears;
        int j, m = p->sesquence;
        NearbyPro *q = p->near;
        for (j = 0; j < i; j++) {
            int n = q->seq;
            c[m][n] = 1;
            q = q->next;
        }
        p = p->next;
    }
    p = head->next;
    int i, k;
    for(i = 1; i <= n;i++)
        colors[i] = 0;
    k = 1;
    while(k >= 1){

        colors[k] = colors[k]+1;
        while(colors[k] <= m)
            if(ColorIsRight(k,c))
                break;
            else
                colors[k] = colors[k]+1;//搜索下一个颜色
        if(colors[k] <=m && k==n){

        char tag[100];
        sprintf(tag, "%d.txt", count);
        FILE *fp = fopen(tag,"w+");
           char s[100];
            for(i = 1; i <= n; i++){
                //                p->color = colors[i];
                //                p = p->next;

                printf("%d\n",colors[i]);
                fprintf(fp, "%d\n",colors[i]);

            }
                fclose(fp);
            count++;
            printf("\n");
            if(count == 4){break;}


        }
        else if(colors[k] <= m && k < n)
            k = k+1;//处理下一个顶点
        else{
            colors[k] = 0;
            k = k-1;//回溯
        }
    }

}

void Scripts(Provience *p){
    int i;
    for (i = 1; i <= 34; i++) {
        char s[100];
        char tag[100];
        sprintf(tag, "button%d", p->sesquence);
        sprintf(s, "/Users/Mauri/Desktop/Map/%s.cs", tag);
        FILE *fp = fopen(s,"w+");

        if(!fp){
            printf("no documents!\n");
            return ;
        }
        fprintf(fp, "using UnityEngine;\nusing System.Collections;\nusing System.Runtime.InteropServices;\n\n");
        fprintf(fp, "public class %s : MonoBehaviour{", tag);
        fprintf(fp, "\tprivate bool flag;\n\tprivate GameObject Obj;\n\tpublic GUIStyle font = new GUIStyle();\n\tvoid Start(){\n\t\tflag = false;\n\t}\n\n\tvoid Update() {\n\t\tif (Input.GetMouseButtonDown(0)) {\n\t\t\tflag = true;\n\t\t}\n\t\tif (Input.GetMouseButtonDown(1)) {\n\t\t\tflag = false;\n\t\t}\n\t}");
        fprintf(fp, "\n\tvoid OnGUI(){\n\t\tif (flag){");
        fprintf(fp, "\n\t\t\tGUI.Box(new Rect(800, 20, 200, 150), \"%s\",font);\n\t\t\tGUILayout.BeginArea(new Rect(800, 50, 200, 200));\n\t\t\tGUILayout.Label(str);\n\t\t\tGUILayout.Label(\"省会：%s\");\n\t\t\tGUILayout.Label(\"区号：%s\");\n\t\t\tGUILayout.Label(\"人口：%.2lf万人\");\n\t\t\tGUILayout.EndArea();", p->name, p->captail, p->num, p->popultion);
        fprintf(fp, "\n\t\t}\n\t}\n}");
        p = p->next;
    }

}
void createdGraph(PGraph g, Provience *head){
    int i, j;
    g->vertexNum = 32;
    g->edgeNum = 68;
    for(i = 0; i < g->vertexNum; i++)
        g->vertex[i] = 1+i;
    for(i = 0; i < g->vertexNum; i++)
        for(j = 0; j <g->vertexNum; j++)
            g->arc[i][j] = 0;
    Provience *p = head->next;
    while (p) {
        int a = p->nears;
        int b, m = p->sesquence;
        NearbyPro *q = p->near;
        for (b = 0; b < a; b++) {
            int n = q->seq;
            g->arc[m-1][n-1] = q->distance;
            q = q->next;
        }
        p = p->next;
    }
    //    for(i = 0; i < g->vertexNum; i++){
    //        for(j = 0; j <g->vertexNum; j++)
    //            printf("%5d ", g->arc[i][j]);
    //        printf("\n");
    //    }
    //
}
void initTree(PGraph tree)
{
    int i, j;
    tree->vertexNum = 32;
    tree->edgeNum = 31;
    for(i = 0; i < tree->vertexNum; i++)
        tree->vertex[i] = '0';
    for(i = 0; i < tree->vertexNum; i++)
        for(j = 0; j < tree->vertexNum; j++)
            tree->arc[i][j] = 0;
}

//普里姆算法求最小生成树
void prim(PGraph g,PGraph tree)
{
    FILE *fp = fopen("mintree.txt", "w+");
    int i, j, k;
    int index;//指向权值最小的边
    ArrayNode edgeArray[200];//辅助数组
    int length=0;//数组长度
    int n = 1;//统计数组已加入多少个顶点
    //初始状态把第一个顶点加入树中
    tree->vertex[0] = 1;
    i=0;
    while(1){
        //寻找与顶点i相接且这条边的另一个顶点不在树中的边,存入edgeArray数组中
        for(j = 0; j < g->vertexNum; j++){
            if(g -> arc[i][j] > 0){
                //判断这条边的另一个顶点在不在树中
                for(k = 0; k < tree->vertexNum; k++){
                    if(tree->vertex[k] == g->vertex[j])
                        break;
                }
                if(k == tree->vertexNum){
                    edgeArray[length].from = i;
                    edgeArray[length].to = j;
                    edgeArray[length].weight = g->arc[i][j];
                    edgeArray[length].flag = 0;
                    length++;
                }
            }
        }
        //从数组中选择权值最小的边
        index = -1;
        for(j = 0; j < length; j++){
            if(index == -1 && edgeArray[j].flag == 0)
                index = j;
            if(edgeArray[j].flag == 0 && edgeArray[j].weight < edgeArray[index].weight)
                index = j;
        }
        //在树中加入一个顶点，且把这条权值最小的边加入树中
        tree->vertex[edgeArray[index].to] = 1 + edgeArray[index].to;
        edgeArray[index].flag = 1;
        tree->arc[edgeArray[index].from][edgeArray[index].to] = edgeArray[index].weight;
        tree->arc[edgeArray[index].to][edgeArray[index].from] = edgeArray[index].weight;
        //当这个顶点加入树中时，与这个顶点相邻的边不可加入树中
        for(k = 0; k<length; k++){
            if(edgeArray[k].to == edgeArray[index].to)
                edgeArray[k].flag = 1;
        }
        i = edgeArray[index].to;
        int kuu = edgeArray[index].from;
        fprintf(fp, "%d\n",tree->vertex[kuu]);
        fprintf(fp, "%d\n", tree->vertex[i]);

        n++;
        //当有g->vertexNum个顶点时，最小生成树构造完成
        if(n == g->vertexNum)
            break;
    }
            fclose(fp);
}
