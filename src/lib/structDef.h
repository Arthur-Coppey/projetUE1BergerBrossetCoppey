#ifndef MODULE2_SETTINGS_SRC_LIB_STRUCTDEF_H_
#define MODULE2_SETTINGS_SRC_LIB_STRUCTDEF_H_

struct led {
	int id;
	int state;
};

struct step {
	int index;
	struct led leds[10];
	struct step * next;
};

struct sequence {
	struct step * first;
	int length;
};

#endif /* MODULE2_SETTINGS_SRC_LIB_STRUCTDEF_H_ */
