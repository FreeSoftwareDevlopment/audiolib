#ifdef AUDIOVOLUMECONTROL_EXPORTS
#define AUDIOVOLUMECONTROL_API __declspec(dllexport)
#else
#define AUDIOVOLUMECONTROL_API __declspec(dllimport)
#endif
#include <stdlib.h>
typedef unsigned int uint;
typedef uint* audioChannel;

AUDIOVOLUMECONTROL_API class audio {
private:
	bool fault = false;
	void* audioEndpoint;
public:
	AUDIOVOLUMECONTROL_API audio();
	AUDIOVOLUMECONTROL_API void setVolume(float vol, audioChannel channel = nullptr);
	AUDIOVOLUMECONTROL_API float getVolume(audioChannel channel = nullptr);
	AUDIOVOLUMECONTROL_API void setVolume(int vol, audioChannel channel = nullptr);
	AUDIOVOLUMECONTROL_API bool isMute();
	AUDIOVOLUMECONTROL_API void mute(bool mute = true);
	AUDIOVOLUMECONTROL_API uint channels();
	AUDIOVOLUMECONTROL_API void step(bool up = true);
	const bool& getFault() { return fault; }
	AUDIOVOLUMECONTROL_API ~audio();
};
