using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.IO;

public class Colors3 : MonoBehaviour
{
    private string[] strs;
    void Start()
    {

    }
    // Update is called once per frame
    void Update()
    {
        string Dpath = Application.dataPath;
        int num = Dpath.LastIndexOf("/");
        Dpath = Dpath.Substring(0, num);
        string url = Dpath + "/3.txt";
        strs = File.ReadAllLines(url);
    }
    public void ButtonClick(GameObject button)
    {
        int i;
        for (i = 1; i <= 32; i++)
        {
            string str = i.ToString();
            GameObject now = GameObject.Find(str);
            int a = int.Parse(strs[i - 1]);
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
    // Use this for initialization

}
