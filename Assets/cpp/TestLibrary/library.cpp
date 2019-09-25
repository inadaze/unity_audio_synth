#include "library.h"
#include "Talker.h"
#include "SineWave.h"
#include "FileLoop.h"
#include "FileWvOut.h"

#include <iostream>
#include <RtWvOut.h>


void hello() {
    std::cout << "Hello, World!" << std::endl;
}


Talker* create_talker() {
    return new Talker();
}

void talker_talk(Talker* pTalker) {
    return pTalker->say_hello();
}

void makeSineWave () {
    // Set the global sample rate before creating class instances.
    stk::Generator::setSampleRate( 44100.0 );
    stk::FileLoop input;
    stk::FileWvOut output;
    // Load the sine wave file.
    input.openFile( "/Users/jasons/Desktop/ConsoleApp1/cpp/LibStk/rawwaves/sinewave.raw", true );
    // Open a 16-bit, one-channel WAV formatted output file
    output.openFile( "/Users/jasons/Desktop/hellosine.wav", 1, stk::FileWrite::FILE_WAV, stk::FileRead::STK_SINT16 );
    input.setFrequency( 440.0 );
    // Run the oscillator for 40000 samples, writing to the output file
    for ( int i=0; i<40000; i++ )
        output.tick( input.tick() );
}

void makeRtSineWave() {
    stk::Generator::setSampleRate( 44100.0 );
    stk::Generator::showWarnings( true );

    int nFrames = 100000;

    stk::RtWvOut *dac = 0;
    try {
        // Define and open the default realtime output device for one-channel playback
        dac = new stk::RtWvOut( 1 );
    }
    catch ( stk::StkError & ) {
        exit( 1 );
    }

    float base_freq = 220.0;
    stk::SineWave sine;
    sine.setFrequency( 441.0 );

    // Option 2: Single-sample computations
    for ( int i=0; i<nFrames; i++ ) {
        try {
            dac->tick( sine.tick() );
        }
        catch ( stk::StkError & ) {
            goto cleanup;
        }
    }

    cleanup:
    delete dac;
}
