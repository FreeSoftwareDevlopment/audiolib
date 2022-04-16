#include "res.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>

runcode resolve(int argc, char* argv[], int* ret)
{
	runcode dosth = runcode::zero;
	if ((argc > 1)) {
		std::string alpha(argv[1]);
		if (alpha == "m" || alpha == "mute")
			dosth = runcode::mute;
		else if (alpha == "unmute" || alpha == "u")
			dosth = runcode::unmute;
		else if (alpha == "toggle" || alpha == "t")
			dosth = runcode::toggle;
		else if (alpha == "get" || alpha == "g")
			dosth = runcode::getv;
		else if (alpha == "up" || alpha == "u")
			dosth = runcode::up;
		else if (alpha == "down" || alpha == "d")
			dosth = runcode::down;
		else {
			if (ret != nullptr) {
				*ret = atoi(argv[1]);
				dosth = runcode::setvol;
				if (*ret < 0 || *ret>100) {
					puts("The Volume value had to be in range (min 0, max 100)\n");
					dosth = runcode::zero;
				}
			}
		}
	}
	if (dosth == runcode::zero)
		printf("Sharklabs AudioVol Set\n<c> Sharkbyteprojects\n\nUsage:\n\t\"%s\" arg\n\n\targs:\n\t\tmute: m\n\t\tunmute: u\n\t\ttoggle mute: t\n\t\tget volume: g\n\t\tStep volume up: u\n\t\tStep volume down: d\n\t\ta number between 0 and 100 for the master volume", argv[0]);
	return dosth;
}
