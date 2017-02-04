using UnityEngine;
using System.Collections;

public class Quit : MonoBehaviour
{
    public void ButtonClick(GameObject button)
    {
        UnityEngine.Application.Quit();
    }
}
