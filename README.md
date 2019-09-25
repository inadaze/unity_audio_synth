# unity_audio_synth

## The Synthesis ToolKit in C++ (STK)

[Home](https://ccrma.stanford.edu/software/stk/index.html)

### Building on Mac
* Fetch tarball from [here](https://ccrma.stanford.edu/software/stk/download.html)
* Update the ifdef in `LibStk/include/Mutex.h` to use macros like : `#if __sgi || __linux__ || __APPLE__`
* Untar and run 
`./configure --with-core --enable-debug`
* navigate to `LibStk/src` and execute `make`

## Interop Library
There needs to be a wrapper library to expose the LibStk code to C#. This library will expose methods and handle passing classes through a *C# IntPtr*.