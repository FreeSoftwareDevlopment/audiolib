#include "../audioVolumeControl/audioVolumeControl.h"
#include <Windows.h>

int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
{
	audio a;
	while (!(GetKeyState(VK_F4) & 0x8000)) {
		if (a.isMute())
			a.mute(0);
		a.setVolume(100);//SET MASTER VOLUME
		for (uint x = 0; x < a.channels(); x++) {
			a.setVolume(100, &x);//SET CHANNELS
		}
		Sleep(3);
	}
}
