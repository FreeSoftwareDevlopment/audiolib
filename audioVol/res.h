#pragma once
enum class runcode {
	zero,
	mute,
	unmute,
	setvol,
	toggle,
	getv,
	up,
	down
};

runcode resolve(int argc, char* argv[], int* = nullptr);
