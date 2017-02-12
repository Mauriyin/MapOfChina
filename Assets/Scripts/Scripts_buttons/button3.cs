using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class button3 : MonoBehaviour{
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
			GUI.Box(new Rect(800, 20, 200, 150), "河北省",font);
			GUILayout.BeginArea(new Rect(800, 50, 200, 200));
			GUILayout.Label("省会：石家庄");
			GUILayout.Label("区号：0311");
			GUILayout.Label("人口：7185.42万人");
			GUILayout.EndArea();
		}
	}
}