using UnityEngine;
using System.Collections;

public class Reset : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		
	}
	public void ButtonClick(GameObject button)
	{
		int i;
		for(i = 1; i <= 32; i++) {
			string str = i.ToString();
			GameObject now = GameObject.Find(str);
			now.GetComponent<SpriteRenderer>().material.color = Color.white;
		}
		GameObject nows = GameObject.Find("Main Camera");
		nows.GetComponent<DrawLineDemo>().enabled = false;
	}
}
