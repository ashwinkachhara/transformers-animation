#include "gl_framework.hpp"
#include "robot.hpp"

#include "load_texture.hpp"
#include "draw_shapes.hpp"
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
//R/V	RootTransX	RootTransY	RootTransZ	RootRotX	RootRotY	RootRotZ\n
#define KF_FORMAT "R/V\tRootTransX\tRootTransY\tRootTransZ\tRootRotX\tRootRotY\tRootRotZ\n"

GLuint torso_tex;
GLuint skybox_dn, skybox_up, skybox_lf, skybox_rt, skybox_ft, skybox_bk;
GLuint cloud;

void init_textures(void){
	torso_tex = loadTexture("texture/paris.bmp");
	skybox_dn = loadTexture("texture/skybox/dn.bmp");
	skybox_up = loadTexture("texture/skybox/up.bmp");
	skybox_lf = loadTexture("texture/skybox/lf.bmp");
	skybox_rt = loadTexture("texture/skybox/rt.bmp");
	skybox_ft = loadTexture("texture/skybox/ft.bmp");
	skybox_bk = loadTexture("texture/skybox/bk.bmp");
	cloud = loadTexture("texture/smoketex.bmp");
}

void init_kf_file(void){
	std::ofstream kf_file;
	kf_file.open(KF_FILE, std::ios::out);
	kf_file << KF_FORMAT;
	kf_file.close();
}

int main(int argc, char** argv){
	//! The pointer to the GLFW window
	GLFWwindow* window;

	//! Setting up the GLFW Error callback
	glfwSetErrorCallback(csX75::error_callback);

	//! Initialize GLFW
	if (!glfwInit())
	return -1;

	//! Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(800, 800, "CS475 Assignment 2.2 | 10D070048 | 10D070001", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	//! Make the window's context current 
	glfwMakeContextCurrent(window);

	//Initialize GLEW
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		//Problem: glewInit failed, something is seriously wrong.
		std::cerr<<"GLEW Init Failed : %s"<<std::endl;
	}

	//Print and see what context got enabled
	std::cout<<"Vendor: "<<glGetString (GL_VENDOR)<<std::endl;
	std::cout<<"Renderer: "<<glGetString (GL_RENDERER)<<std::endl;
	std::cout<<"Version: "<<glGetString (GL_VERSION)<<std::endl;
	std::cout<<"GLSL Version: "<<glGetString (GL_SHADING_LANGUAGE_VERSION)<<std::endl;

	//Keyboard Callback
	glfwSetKeyCallback(window, key_callback);
	//Framebuffer resize callback
	glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	//Initialize GL state
	csX75::initGL();
	init_structures();
	
	init_textures();
	// Loop until the user closes the window
	
	init_kf_file();
	
	//~ Initializing transformer in state = sVEHICLE 
	reset_angles_H();
	transform();
	
	while (glfwWindowShouldClose(window) == 0)
	{

		// Render here
		renderGL();
		movement();
		// Swap front and back buffers
		glfwSwapBuffers(window);
		
		if ((state == sHUMANOID) || (state == sVEHICLE)){
			// Poll for and process events
			glfwPollEvents();
		} else {
			//~ usleep(TF_DELAY_uS);
			//~ right_hip_rot.set(20, 50, 82);
		}
	}

	glfwTerminate();
	return 0;
}

