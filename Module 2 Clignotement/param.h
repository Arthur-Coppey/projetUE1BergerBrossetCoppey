#ifndef MODULE2_SETTINGS_SRC_PARAM_H_
#define MODULE2_SETTINGS_SRC_PARAM_H_
int led_0_0[2] = {4,0};
int led_0_1[2] = {5,1};
int led_0_2[2] = {6,0};
int led_0_3[2] = {7,1};
int led_0_4[2] = {8,0};
int led_0_5[2] = {9,1};
int led_0_6[2] = {10,0};
int led_0_7[2] = {11,1};
int led_0_8[2] = {12,0};
int led_0_9[2] = {13,1};
int *step_0[10] = {led_0_0,led_0_1,led_0_2,led_0_3,led_0_4,led_0_5,led_0_6,led_0_7,led_0_8,led_0_9};
int led_1_0[2] = {4,1};
int led_1_1[2] = {5,0};
int led_1_2[2] = {6,1};
int led_1_3[2] = {7,0};
int led_1_4[2] = {8,1};
int led_1_5[2] = {9,0};
int led_1_6[2] = {10,1};
int led_1_7[2] = {11,0};
int led_1_8[2] = {12,1};
int led_1_9[2] = {13,0};
int *step_1[10] = {led_1_0,led_1_1,led_1_2,led_1_3,led_1_4,led_1_5,led_1_6,led_1_7,led_1_8,led_1_9};
int ** sequence[2] = {step_0,step_1};
#endif /* MODULE2_SETTINGS_SRC_PARAM_H_ */
