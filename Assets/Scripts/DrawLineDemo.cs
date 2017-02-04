using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.IO;

public class DrawLineDemo : MonoBehaviour
{
    public Material mat;
    
    private GameObject LineRenderGameObject;
    Vector3 first;
    Vector3 second;

    private string[] strs;

    public Camera cam;


    // Use this for initialization
    void Start()
    {
        string Dpath = Application.dataPath;
        int num = Dpath.LastIndexOf("/");
        Dpath = Dpath.Substring(0, num);
        string url = Dpath + "/mintree.txt";
        strs = File.ReadAllLines(url);
        

    }


    void OnPostRender()
    {
        int i;
        for (i = 1; i <= 62; i++)
        {
            string str1 = strs[i - 1];
            string str2 = strs[i];
            //print(str1);
            GameObject provience1 = GameObject.Find(str1+"/Circle");
            //provience1.GetComponent<SpriteRenderer>().material.color = Color.black;
            first = cam.WorldToViewportPoint(provience1.transform.position);
            GameObject provience2 = GameObject.Find(str2+"/Circle");
            //provience2.GetComponent<SpriteRenderer>().material.color = Color.black;
            second = cam.WorldToViewportPoint(provience2.transform.position);
            //print(second);
            GL.PushMatrix();
            mat.SetPass(0);
            //绘制2D线段，注释掉GL.LoadOrtho();则绘制3D图形
            GL.LoadOrtho();
            //开始绘制直线类型，需要两个顶点
            GL.Begin(GL.LINES);
            //绘制起点，绘制的点需在Begin和End之间
            GL.Vertex3(first.x, first.y, first.z - 10);
            GL.Vertex3(second.x, second.y, second.z - 10);
            GL.End();
            GL.PopMatrix();
            i++;
        }

       
    }
}