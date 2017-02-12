//
//  main.c
//  Map
//
//  Created by 阴浩 on 20/01/2017.
//  Copyright © 2017 yhMaruriYin. All rights reserved.
//


#include "Provience.h"

int main(int argc, const char * argv[]) {

    Provience *head = (Provience*)malloc(sizeof(Provience));
    int num = LoadFromDoc(head);
    Provience *p = head->next;

    LoadNears(head, num);

    CreateMatrix(head);
//    while (p) {
//        printf("%d\n", p->color);
//        p = p->next;
//    }
    int a[35][35];
    graphcolor(32, 4, a, head);
    int i;
 /*   for (i = 1; i <= 34; i++) {
        char s[100];
        char tag[100];
        sprintf(tag, "button%d", p->sesquence);
        sprintf(s, "/Users/Mauri/Desktop/Map/%s.cs", tag);
        FILE *fp = fopen(s,"w+");

        if(!fp){
            printf("no documents!\n");
            return 0;
        }
        fprintf(fp, "using UnityEngine;\nusing System.Collections;\nusing System.Runtime.InteropServices;\n\n");
        fprintf(fp, "public class %s : MonoBehaviour{", tag);
        fprintf(fp, "\n\tprivate bool flag;\n\tprivate GameObject Obj;\n\tpublic GUIStyle font = new GUIStyle();\n\tvoid Start(){\n\t\tflag = false;\n\t\tfont.fontSize = 20;\n\t}\n\n\tvoid OnMouseDown(){\n\t\tflag = true;\n\t}\n\tvoid OnMouseExit(){\n\t\tflag = false;\n\t}");
        fprintf(fp, "\n\tvoid OnGUI(){\n\t\tif (flag){");
        fprintf(fp, "\n\t\t\tGUI.Box(new Rect(800, 20, 200, 150), \"%s\",font);\n\t\t\tGUILayout.BeginArea(new Rect(800, 50, 200, 200));\n\t\t\tGUILayout.Label(\"省会：%s\");\n\t\t\tGUILayout.Label(\"区号：%s\");\n\t\t\tGUILayout.Label(\"人口：%.2lf万人\");\n\t\t\tGUILayout.EndArea();", p->name, p->captail, p->num, p->popultion);
        fprintf(fp, "\n\t\t}\n\t}\n}");
        p = p->next;
    }
//
*/
    Graph graph;
    Graph tree;
    createdGraph(&graph, head);
    initTree(&tree);
    printf("普里姆算法树中顶点加入的顺序:\n");
    prim(&graph,&tree);
    printf("\n");


    return 0;
}
