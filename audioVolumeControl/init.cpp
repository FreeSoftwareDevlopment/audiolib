#include "framework.h"
#include "audioVolumeControl.h"

AUDIOVOLUMECONTROL_API audio::audio()
{
	HRESULT hr;
	// -------------------------
	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
	if (hr != S_OK) return;
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	if (hr != S_OK) return;
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
	if (hr != S_OK)return;
	defaultDevice->Release();
	defaultDevice = NULL;
	audioEndpoint = endpointVolume;
}
