#include "res.h"
#include <utility>
#include <iostream>
#include "../audioVolumeControl/audioVolumeControl.h"

void fetcherror(audio* a, const char* task) {
	if (a->getFault()) {
		std::cerr << "An Error occured duing " << task << std::endl;
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char* argv[])
{
	int volume = 0;
	auto r = resolve(argc, argv, &volume);
	if (r == runcode::zero)
		return EXIT_FAILURE;

	audio a;
#define fe(x) fetcherror(&a, x)
	if (r == runcode::setvol) {
		a.setVolume(std::move(volume));
		fe("setVolume");
	}
	else if (r == runcode::getv) {
		float v = a.getVolume();
		fe("Get Volume");
		std::cout << "Master Volume: " << v << std::endl;
	}
	else {
		if (r == runcode::down || r == runcode::up) {
			a.step(r == runcode::up);
			fe("step");
		}
		else
		{
			bool m2 = a.isMute();
			fe("get muted state");
			if (r == runcode::mute || r == runcode::unmute) {
				bool mute = (r == runcode::mute);
				if (mute != m2) {
					a.mute(mute);
					fe("mute");
				}
			}
			else if (r == runcode::toggle) {
				a.mute(!m2);
				fe("mute");
			}
		}
	}
#undef fe
}
