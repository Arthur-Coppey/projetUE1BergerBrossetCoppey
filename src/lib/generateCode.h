#ifndef MODULE2_SETTINGS_SRC_LIB_GENERATECODE_H_
#define MODULE2_SETTINGS_SRC_LIB_GENERATECODE_H_

#include "structDef.h"

int pushStepInSequence(struct sequence *seq, struct step *step);

int newStep(struct sequence *seq, struct led leds[10]);

int showSequence(struct sequence *seq);

int generateFile(struct sequence *seq);

int generateBlink();

int generateOneTwo();

int generateOneThree();

int generateOne(int id);

int generateCaterpillar();

#endif /* MODULE2_SETTINGS_SRC_LIB_GENERATECODE_H_ */
