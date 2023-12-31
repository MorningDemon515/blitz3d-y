
#include "std.h"
#include "bbmath.h"
#include <algorithm>

static int rnd_state;
static const int RND_A = 48271;
static const int RND_M = 2147483647;
static const int RND_Q = 44488;
static const int RND_R = 3399;

static const float dtor = 0.01745329252f; //DEGREES TO RADIANS
static const float rtod = 57.295779513f;  //RADIANS TO DEGREES

float bbSin(float n) { return sin(n * dtor); }
float bbCos(float n) { return cos(n * dtor); }
float bbTan(float n) { return tan(n * dtor); }
float bbASin(float n) { return asin(n) * rtod; }
float bbACos(float n) { return acos(n) * rtod; }
float bbATan(float n) { return atan(n) * rtod; }
float bbATan2(float n, float t) { return atan2(n, t) * rtod; }
float bbSqr(float n) { return sqrtf(n); }
float bbFloor(float n) { return floor(n); }
float bbCeil(float n) { return ceil(n); }
float bbExp(float n) { return exp(n); }
float bbLog(float n) { return log(n); }
float bbLog10(float n) { return log10(n); }
float bbMin(float n, float m) { return fmin(n, m); }
float bbMax(float n, float m) { return fmax(n, m); }
float bbClamp(float v, float lo, float hi) { return std::clamp(v, lo, hi); }
int	bbIsNaN(float n) { return isnan(n); }

//return rand float from 0...1
static inline float rnd() {
	rnd_state = RND_A * (rnd_state % RND_Q) - RND_R * (rnd_state / RND_Q);
	if(rnd_state < 0) rnd_state += RND_M;
	if(rnd_state == 0) {
		rnd_state = RND_R;
	}
	return (rnd_state & 65535) / 65536.0f + (.5f / 65536.0f);
}

float bbRnd(float from, float to) {
	return rnd() * (to - from) + from;
}

int bbRand(int from, int to) {
	if(to < from) std::swap(from, to);
	return int(rnd() * (to - from + 1)) + from;
}

void bbSeedRnd(int seed) {
	seed &= 0x7fffffff;
	rnd_state = seed ? seed : 1;
}

int  bbRndSeed() {
	return rnd_state;
}

bool math_create() {
	bbSeedRnd(0x1234);
	return true;
}

bool math_destroy() {
	return true;
}

void math_link(void (*rtSym)(const char* sym, void* pc)) {
	rtSym("#Sin#degrees", bbSin);
	rtSym("#Cos#degrees", bbCos);
	rtSym("#Tan#degrees", bbTan);
	rtSym("#ASin#float", bbASin);
	rtSym("#ACos#float", bbACos);
	rtSym("#ATan#float", bbATan);
	rtSym("#ATan2#floata#floatb", bbATan2);
	rtSym("#Sqr#float", bbSqr);
	rtSym("#Floor#float", bbFloor);
	rtSym("#Ceil#float", bbCeil);
	rtSym("#Exp#float", bbExp);
	rtSym("#Log#float", bbLog);
	rtSym("#Log10#float", bbLog10);
	rtSym("#Min#n#m", bbMin);
	rtSym("#Max#n#m", bbMax);
	rtSym("#Clamp#v#lo#hi", bbClamp);
	rtSym("%IsNaN#n", bbIsNaN);
	rtSym("#Rnd#from#to=0", bbRnd);
	rtSym("%Rand%from%to=1", bbRand);
	rtSym("SeedRnd%seed", bbSeedRnd);
	rtSym("%RndSeed", bbRndSeed);
}
