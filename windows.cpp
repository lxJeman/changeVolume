// changeVolume - Windows system specific version
// UNTESTED,
// WARNING: Requires Windows SDK to be installed
// Complie via: g++ windows.cpp -o DESIRED_NAME
// Run via: ./DESIRED_NAME

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

int main() 
{
    while (true)
    {
        int volume;

        std::cout << "changeVolume - Linux Version \n";
        std::cout << "Change Volume from 0 to 100:";
        std::cin >> volume;
        std::cout << "\n";

        HRESULT hr = CoInitialize(NULL);
        if (FAILED(hr)) {
            std::cout << "COM initialization failed\n";
            return -1;
        }

        IMMDeviceEnumerator *deviceEnumerator = NULL;
        hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
                            __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);

        IMMDevice *defaultDevice = NULL;
        hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);

        IAudioEndpointVolume *endpointVolume = NULL;
        hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);

        std::string command = std::to_string(volume) + "f";
        
        // Set volume to volume level
        endpointVolume->SetMasterVolumeLevelScalar(command.c_str(), NULL);

        endpointVolume->Release();
        defaultDevice->Release();
        deviceEnumerator->Release();
        CoUninitialize();


    }
    return 0;
}