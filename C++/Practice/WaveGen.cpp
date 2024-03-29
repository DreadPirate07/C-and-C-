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

void writeToFile(std::ofstream &file, int value,int size){
    file.write(reinterpret_cast<const char*> (&value),size);
}

int main()
{
    int duration = 2;
    std::ofstream audioFile;
    // open the audioFile/create it.
    audioFile.open("/home/dreadpirate/CodingPirate/C and C++/C++/waveform",std::ios::binary);
    SineOscillator sineOscillator(440, 0.5);
    
    
    //Header Chunk
    audioFile<<"RIFF";
    audioFile<<"----"; //size
    audioFile <<"WAVE"; //format

    //Format chunk
    audioFile<<"fmt ";
    writeToFile(audioFile,16,4);
    writeToFile(audioFile,1,2); // compression code
    writeToFile(audioFile,1,2); //Number of Channels
    writeToFile(audioFile,sampleRate,4);
    writeToFile(audioFile,sampleRate*bitDepth/8,4); //Byte sampleRate
    writeToFile(audioFile,2,2); // Block align
    writeToFile(audioFile,bitDepth,2);

    //Data chunk
    audioFile <<"data";
    audioFile << "----";



    // loop runs for the time duration we want the audio
    for (int i = 0; i < (sampleRate * duration); i++)
    {
        // //streams data into audioFile
        // audioFile << sineOscillator.process() << std::endl;

        auto sample = sineOscillator.process();
        int intsample = static_cast<int>(sample * 32767);
        writeToFile(audioFile,intsample,2);
    }
    audioFile.close();
    return 0;
}