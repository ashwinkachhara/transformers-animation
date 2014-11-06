#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "gl_framework.hpp"
#include "draw_shapes.hpp"
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define PI 3.1416
#define DEG2RAD 2*PI/360

#define head 1
#define neck 2
#define torso 3
#define right_upper_arm 4
#define left_upper_arm 5
#define right_lower_arm 6
#define left_lower_arm 7
#define right_thigh 8
#define left_thigh 9
#define right_leg 10
#define left_leg 11
#define right_hand 12
#define left_hand 13
#define right_foot 14
#define left_foot 15
#define hand_blade 16
#define heli_chest 17
#define blade_base 18
#define blade 19
#define right_foot_wing 20
#define left_foot_wing 21

#define Y_ANGLE_DEFAULT -45
#define X_ANGLE_DEFAULT 35.264

//~ States of transition
#define sHUMANOID -1
#define sVEHICLE 0
#define sTFone 1
#define sTFtwo 2
#define sTFthree 3
#define sTFfour 4

#define TF_BASE_ROT_V 90
#define TF_BASE_ROT_H 0

#define TF_SHOULDER_ROT_V 100
#define TF_SHOULDER_ROT_H 0

#define TF_ELBOW_ANGLE_V 90
#define TF_ELBOW_ANGLE_H 0

#define TF_KNEE_ANGLE_V 60
#define TF_KNEE_ANGLE_H 0

#define TF_NECK_ANGLE_V 180
#define TF_NECK_ANGLE_H 0

#define TF_FOOT_ANGLE_V 30
#define TF_FOOT_ANGLE_H 0

#define TF_HELI_CHEST_V 180
#define TF_HELI_CHEST_H 0

#define TF_BLADE_DIRECTION_V 0
#define TF_BLADE_DIRECTION_H 180

#define TF_BLADE_GAP_V 180
#define TF_BLADE_GAP_H 15

#define TF_HAND_ANGLE_V 90
#define TF_HAND_ANGLE_H 0

#define TF_FOOT_WING_ANGLE_V 0
#define TF_FOOT_WING_ANGLE_H 90

#define TF_DELAY_uS 100000
#define MOTION_DELAY_uS 100

#define ENV_SIZE 20
#define BILLBOARD_SIZE 0.5

#define CAMERA_GLOBAL 1
#define CAMERA_POV 2
#define CAMERA_FOLLOW 3

#define MODE_FREE 0
#define MODE_RECORD 1
#define MODE_PLAYBACK 2

#define KF_FILE "keyframes.txt"
#define DELTA_T 50


extern float state, prevState;

extern GLuint torso_tex;
extern GLuint skybox_dn, skybox_up, skybox_rt, skybox_lf, skybox_ft, skybox_bk;
extern GLuint cloud;

extern bool doInterpolate;

void kf_interpolate();
void renderGL(void);
void movement(void);
void init_structures(void);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void reset_angles_H(void);
void transform(void);

#endif
