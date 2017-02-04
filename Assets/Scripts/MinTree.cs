using UnityEngine;
using System.Collections;

public class MinTree : MonoBehaviour {
    public void ButtonClick(GameObject obj)
    {
        GameObject now = GameObject.Find("Main Camera");
        now.GetComponent<DrawLineDemo>().enabled = true;
    }
}
