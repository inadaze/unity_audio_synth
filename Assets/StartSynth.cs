using System.Collections;
using System.Collections.Generic;
using System;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.UI;

public class StartSynth : MonoBehaviour
{
    
    [DllImport(@"Assets/cpp/LibStk/cmake-build-debug/libSTK.dylib")]
    public static extern IntPtr SineWaveFactory();
        
    [DllImport(@"Assets/cpp/LibStk/cmake-build-debug/libSTK.dylib")]
    public static extern IntPtr DacFactory();
        
        
    [DllImport(@"Assets/cpp/LibStk/cmake-build-debug/libSTK.dylib")]
    public static extern void PlaySine(IntPtr psine, IntPtr dac);

    public Button m_YourFirstButton;
    public InputField m_InputField;


    // Start is called before the first frame update
    void Start()
    {
        m_YourFirstButton.onClick.AddListener(TaskOnClick);
        m_InputField.text = "440";
        //makeRtSineWave();


    }

    public void TaskOnClick()
    {
        PlaySine(SineWaveFactory(), DacFactory());
    }
    

    
    
}
