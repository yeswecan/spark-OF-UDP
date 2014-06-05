#include <math.h>
#include "commonTypes.h"

class LFO {
public: 
	LFO() {
		currentColor.r = 50;
		currentColor.g = 50;
		currentColor.b = 50;
	};

	// phase: 0 for a sine, 255 for sawtooth
	void addTarget(int r, int g, int b, int funcPeriod, int phase) {
		currentColor.r = r;
		currentColor.g = g;
		currentColor.b = b;
		period = funcPeriod;
		phaseF = (float)phase/255.;
	}

	//--------------------------------------------------------------
	float sawFunc(float arg, float period) {
	    int arg2 = (int)arg;
	    return 2. * ((arg - ((int)arg/(int)period) * (int)period) / (float)period) - 1;
	    //sawtooth = 2. * (((float)i - (i/(int)period) * (int)period) / (float)period) - 1;
	}

	//--------------------------------------------------------------
	float sineFunc(float arg, float period) {
	    return sin(2.0f * M_PI * (arg/(float)period) + 0.5 * M_PI);
	}


	//--------------------------------------------------------------
	void process(int &r, int &g, int &b) {
	    float sawtooth = 1 - sawFunc(millis() / 4., period);
	    float sine = sineFunc(millis() / 4., period);
	    float myArg = sawtooth * phaseF + sine * (1-phaseF);
	    r = currentColor.r * myArg; 
	    g = currentColor.g * myArg;
	    b = currentColor.b * myArg;
	}

private:
	color currentColor;
	int phase, period;
	float phaseF;
	//int targetTime, transitionTime;

};