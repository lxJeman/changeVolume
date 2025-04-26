// changeVolume - Linux system specific version
// UNTESTED, 
// Complie via: clang++ -framework CoreAudio -o DESIRED_NAME macos.cpp
// Run via: ./DESIRED_NAME

#include <iostream>
#include <cstdlib>

int main() 
{
    while (true)
    {
        int volume;

        std::cout << "changeVolume - Linux Version \n";
        std::cout << "Change Volume from 0 to 100:";
        std::cin >> volume;
        std::cout << "\n";

        AudioDeviceID deviceID = 0;
        UInt32 size = sizeof(deviceID);

        AudioObjectPropertyAddress defaultOutputDevicePropertyAddress = {
            kAudioHardwarePropertyDefaultOutputDevice,
            kAudioObjectPropertyScopeGlobal,
            kAudioObjectPropertyElementMain
        };

        AudioObjectGetPropertyData(kAudioObjectSystemObject, &defaultOutputDevicePropertyAddress, 0, NULL, &size, &deviceID);

        // Quick transform value to float
        Float32 volume = static_cast<Float32>(volume) / 100.0f;

        AudioObjectPropertyAddress volumePropertyAddress = {
            kAudioDevicePropertyVolumeScalar,
            kAudioDevicePropertyScopeOutput,
            0
        };

        AudioObjectSetPropertyData(deviceID, &volumePropertyAddress, 0, NULL, sizeof(volume), &volume);

        
    }

    return 0;
}