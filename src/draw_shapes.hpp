#ifndef _DRAW_SHAPES_HPP_
#define _DRAW_SHAPES_HPP_

#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>
#include <unistd.h>

#define PI 3.1416



void drawTetrahedron(float s);
void drawCuboidTetrahedron(float l, float b, float h);

void drawCubeWireframe();

void drawCuboidSolid(float l, float b, float h);

void drawSphere(float r, float res);
void drawSphereInwards(float r, float res);

void drawCylinder(float r, float h, float res);
void drawCuboidEdgeYd(float l, float b, float h);
void drawPrism(float l, float b, float h );

#endif
