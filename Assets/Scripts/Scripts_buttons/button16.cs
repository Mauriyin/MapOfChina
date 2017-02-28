using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.IO;
public class button16 : MonoBehaviour{
	private bool flag;
	private GameObject Obj;
	public GUIStyle font = new GUIStyle();
	void Start(){
		flag = false;
		font.fontSize = 20;
	}

	private string[] strs;
	void Update()
	{
		string Dpath = Application.dataPath;
		int num = Dpath.LastIndexOf("/");
		Dpath = Dpath.Substring(0, num);
		string url = Dpath + "/16.txt";
		strs = File.ReadAllLines(url);
		Debug.Log(strs);
	}
	void OnMouseDown(){
		flag = true;
		int i;
		for(i = 1; i <= 32; i++) {
			string str = i.ToString();
			GameObject now = GameObject.Find(str);
			int a = int.Parse(strs[i-1]);
			switch (a)
			{
			case 1:
				now.GetComponent<SpriteRenderer>().material.color = Color.blue;
				break;
			case 2:
				now.GetComponent<SpriteRenderer>().material.color = Color.yellow;
				break;
			case 3:
				now.GetComponent<SpriteRenderer>().material.color = Color.red;
				break;
			case 4:
				now.GetComponent<SpriteRenderer>().material.color = Color.green;
				break;
			}

		}
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