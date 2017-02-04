using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class button16 : MonoBehaviour{
	private bool flag;
	private GameObject Obj;
	public GUIStyle font = new GUIStyle();
	void Start(){
		flag = false;
		font.fontSize = 20;
	}

	void OnMouseDown(){
		flag = true;
	}
	void OnMouseExit(){
		flag = false;
	}
	void OnGUI(){
		if (flag){
			GUI.Box(new Rect(800, 20, 200, 150), "河南省",font);
			GUILayout.BeginArea(new Rect(800, 50, 200, 200));
			GUILayout.Label("省会：郑州市");
			GUILayout.Label("区号：0371");
			GUILayout.Label("人口：9402.36万人");
			GUILayout.EndArea();
		}
	}
}