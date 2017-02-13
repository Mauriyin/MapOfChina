using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.IO;
using System.Diagnostics;
public class Init : MonoBehaviour {
    GameObject now5, now1, now2, now3, now4, now6;
    private string url;
    static bool flag;
    void Start()
    {
        string Dpath = Application.dataPath;
        int num = Dpath.LastIndexOf("/");
        Dpath = Dpath.Substring(0, num);
        url = Dpath + "/a.exe";
        now1 = GameObject.Find("Canvas/Button1");
        now1.SetActive(false);

        now2 = GameObject.Find("Canvas/Button2");
        now2.SetActive(false);

        now3 = GameObject.Find("Canvas/Button3");
        now3.SetActive(false);

        now4 = GameObject.Find("Canvas/Button4");
        now4.SetActive(false);

        now5 = GameObject.Find("Canvas/Button5");
        now5.SetActive(false);

        now6 = GameObject.Find("Canvas/Button6");
        now6.SetActive(false);

        flag = false;
    }

    public void ButtonClick(GameObject game)
    {

        Process.Start(url);
        now1.SetActive(true);

        now2.SetActive(true);
        
        now3.SetActive(true);
       
        now4.SetActive(true);
     
        now5.SetActive(true);

        now6.SetActive(true);
        flag = true;
        if (flag) { print("sssss1111"); }
       
    }
    void Update()
    {
        if (flag) {
            print("1111");
            now2.GetComponent<Colors2>().enabled = true;
            now1.GetComponent<Colors>().enabled = true;
            now3.GetComponent<Colors3>().enabled = true;
        }
    }
}
