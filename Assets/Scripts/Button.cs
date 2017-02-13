using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class Button : MonoBehaviour {

    private bool flag;
    private GameObject Obj;
    public GUIStyle font = new GUIStyle();
    void Start(){
        flag = false;
    }

    void Update() {
        if (Input.GetMouseButtonDown(0)) {
            flag = true;
        }
        if (Input.GetMouseButtonDown(1)) {
            flag = false;
        }
    }

    void OnGUI()
    {
        if (flag)
        {
            
            string yourCustomString = "I don 't Know ";
            string str = string.Format("Hello {0} ", yourCustomString);
            GUI.Box(new Rect(800, 20, 200, 150), "内蒙古自治区",font);
            GUILayout.BeginArea(new Rect(800, 50, 200, 200));
            GUILayout.Label(str);
            GUILayout.Label("区号：");
            GUILayout.Label("人口：");
            GUILayout.Label("相邻省分：");
            GUILayout.EndArea();
        }
    }

}

