using System.Collections;
using System.Collections.Generic;
using System;
using System.Runtime.InteropServices;
using UnityEngine;

public class StartSynth : MonoBehaviour
{
    
    [DllImport(@"Assets/cpp/TestLibrary/cmake-build-debug/libTestLibrary.dylib")]
    public static extern void makeRtSineWave();
    
    
    // Start is called before the first frame update
    void Start()
    {
        makeRtSineWave();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    
}
