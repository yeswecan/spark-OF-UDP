#include <math.h>
#include "commonTypes.h"

class Interpolator {

public:
	Interpolator() {
		currentColor.r = 50;
		currentColor.g = 50;
		currentColor.b = 50;

		targetColor.r = 50;
		targetColor.g = 50;
		targetColor.b = 50;
	}

	void addTarget(int r, int g, int b, int transitionTimeframe) {
        if ((r != targetColor.r)||(g != targetColor.g)||(b != targetColor.b)) {
            
            if (transitionTimeframe != 0){
            
                previousColor.r = currentColor.r;
                previousColor.g = currentColor.g;
                previousColor.b = currentColor.b;
                //
                targetColor.r = r;
                targetColor.g = g;
                targetColor.b = b;

                // defaulting transition to second
                transitionTime = transitionTimeframe;

                targetTime = millis() + transitionTimeframe;
            } else { // transition time is zero
                previousColor.r = r;
                previousColor.g = g;
                previousColor.b = b;
                //
                targetColor.r = r;
                targetColor.g = g;
                targetColor.b = b;
                
                //r =O2Spacket.r;
                //g =O2Spacket.g;
                //b =O2Spacket.b;
                
                
                transitionTime = 0;
                
                targetTime = millis();
                
            }
        }
	}

	void process(int &r, int &g, int &b) {
	    if ((targetColor.r != r)||(targetColor.g != g)||(targetColor.b != b)) {
	        if (millis() > targetTime || transitionTime == 0) {
	            r = targetColor.r;
	            g = targetColor.g;
	            b = targetColor.b;
	        } else {
	            float timeFrame = (targetTime - millis());
	            float phase = 1 - (timeFrame)/(float)transitionTime;
	            float easingFunc = pow(phase, 2) / (pow(phase,2) + pow(1 - phase, 2));
	            // setting up r,g,b with easing func:
	            r = previousColor.r + (int)((float)targetColor.r - (float)previousColor.r) * easingFunc;
	            g = previousColor.g + (int)((float)targetColor.g - (float)previousColor.g) * easingFunc;
	            b = previousColor.b + (int)((float)targetColor.b - (float)previousColor.b) * easingFunc;
	        }
	    }
	}

private:
	color previousColor, targetColor, currentColor;
	int targetTime, transitionTime;

};