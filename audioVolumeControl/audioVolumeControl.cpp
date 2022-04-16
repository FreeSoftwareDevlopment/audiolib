#include "framework.h"
#include "audioVolumeControl.h"

#define endpointVolume static_cast<IAudioEndpointVolume*>(audioEndpoint)
#define checkfault(x) fault = x != S_OK
#define allInclusive(x) checkfault(endpointVolume->x)

AUDIOVOLUMECONTROL_API void audio::setVolume(float vol, audioChannel channel)
{
	vol /= 100;
	if (channel == nullptr)
		allInclusive(SetMasterVolumeLevelScalar(vol, NULL));
	else
		allInclusive(SetChannelVolumeLevelScalar(*channel, vol, NULL));
}

float audio::getVolume(audioChannel channel)
{
	float vol = .0f;
	if (channel == nullptr)
		allInclusive(GetMasterVolumeLevelScalar(&vol));
	else
		allInclusive(GetChannelVolumeLevelScalar(*channel, &vol));
	return vol * 100;
}

AUDIOVOLUMECONTROL_API void audio::setVolume(int vol, audioChannel channel)
{
	setVolume(static_cast<float>(vol), channel);
}

AUDIOVOLUMECONTROL_API bool audio::isMute()
{
	BOOL muted = 0;
	allInclusive(GetMute(&muted));
	return muted == 1;
}

AUDIOVOLUMECONTROL_API void audio::mute(bool mute)
{
	allInclusive(SetMute(mute ? 1 : 0, NULL));
}

AUDIOVOLUMECONTROL_API audio::~audio()
{
	endpointVolume->Release();
}

AUDIOVOLUMECONTROL_API void audio::step(bool up)
{
	if (up)
		allInclusive(VolumeStepUp(NULL));
	else
		allInclusive(VolumeStepDown(NULL));
}

AUDIOVOLUMECONTROL_API uint audio::channels()
{
	UINT channel = 0;
	allInclusive(GetChannelCount(&channel));
	return channel;
}
