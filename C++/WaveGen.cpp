#include <iostream>
#include <cmath>
#include <fstream>

const int sampleRate = 44100;
const int bitDepth = 16;

class SineOscillator
{
    float frequency, amplitude, offset, angle;

public:
    SineOscillator(float freq, float amp) : frequency(freq), amplitude(amp)
    {
        offset = 2 * M_PI * frequency / sampleRate;
    }

    float process()
    {
        // returns the value of Asin(2PIf/sr)
        auto sample = amplitude * sin(angle);
        angle += offset;
        return sample;
    }
};

int main()
{
    int duration = 2;
    std::ofstream audioFile;
    // open the audioFile/create it.
    audioFile.open("/home/dreadpirate/CodingPirate/C and C++/C++/waveform");
    SineOscillator sineOscillator(440, 0.5);
    // loop runs for the time duration we want the audio
    for (int i = 0; i < (sampleRate * duration); i++)
    {
        //streams data into audioFile
        audioFile << sineOscillator.process() << std::endl;
    }
    audioFile.close();
    return 0;
}