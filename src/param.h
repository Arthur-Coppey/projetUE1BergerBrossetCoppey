#ifndef MODULE2_SETTINGS_SRC_PARAM_H_
#define MODULE2_SETTINGS_SRC_PARAM_H_

typedef struct led {
	int id;
	int state;
} led;

typedef struct step {
	led leds[10];
	struct step * next;
} step;

typedef struct sequence {
	step * first;
	int length;
} sequence;



#endif /* MODULE2_SETTINGS_SRC_PARAM_H_ */
