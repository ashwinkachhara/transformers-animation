#include "draw_shapes.hpp"

void drawTetrahedron(float s){
    glBegin(GL_TRIANGLES);

    glNormal3f(0, 0.577, -0.816);
    glVertex3f(-s/2, 0, -s*0.707/2);
    glVertex3f(0, s/2, s*0.707/2);
    glVertex3f(s/2, 0, -s*0.707/2);
    
    glNormal3f(0, -0.577, -0.816);
    glVertex3f(s/2, 0, -s*0.707/2);
    glVertex3f(0, -s/2, s*0.707/2);
    glVertex3f(-s/2, 0, -s*0.707/2);
        
    glNormal3f(0.577, 0, 0.816);
    glVertex3f(s/2, 0, -s*0.707/2);
    glVertex3f(0, s/2, s*0.707/2);
    glVertex3f(0, -s/2, s*0.707/2);
    
    glNormal3f(-0.577, 0, 0.816);
    glVertex3f(-s/2, 0, -s*0.707/2);
    glVertex3f(0, -s/2, s*0.707/2);
    glVertex3f(0, s/2, s*0.707/2);

    glEnd();
}

void drawCuboidTetrahedron(float l, float b, float h){
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
    
	    glNormal3f(0, 0, -1); // Back
	    glVertex3f( 0, -b/2, -h/2 );
	    glVertex3f( -l/2,  b/2, -h/2 );
	    glVertex3f(  l/2,  b/2, -h/2 );
	    
	    //~ glNormal3f(1, 0, 0);// RIGHT
	    float face_norm = sqrt(b*h*b*h+ l*h*l*h + l*b*l*b);
	    glNormal3f(b*h/face_norm, l*h/face_norm, l*b/face_norm);
	    glVertex3f( 0,  b/2,  h/2 );
	    glVertex3f( 0, -b/2, -h/2 );
	    glVertex3f(  l/2,  b/2, -h/2 );
	    
	    //~ glNormal3f(-1, 0, 0);// LEFT
	    glNormal3f(-b*h/face_norm, l*h/face_norm, l*b/face_norm);
	    glVertex3f(  -l/2,  b/2, -h/2 );
	    glVertex3f( 0, -b/2, -h/2 );
	    glVertex3f(  0,  b/2,  h/2 );
	    
	    // glColor4f(1,0,1,1);
	    glNormal3f(0, 1, 0);// TOP
	    glVertex3f(  0,  b/2,  h/2 );
	    glVertex3f(  l/2,  b/2, -h/2 );
	    glVertex3f( -l/2,  b/2, -h/2 );
	    
        

        // // Inner side of tetrahedron
        // glNormal3f(0, 0, 1); // Back
        // glVertex3f( -l/2,  b/2, -h/2 );
        // glVertex3f( 0, -b/2, -h/2 );
        // glVertex3f(  l/2,  b/2, -h/2 );
        

        // //~ glNormal3f(1, 0, 0);// RIGHT
        // glNormal3f(-b*h/face_norm, -l*h/face_norm, -l*b/face_norm);
        // glVertex3f( 0, -b/2, -h/2 );
        // glVertex3f( 0,  b/2,  h/2 );
        // glVertex3f(  l/2,  b/2, -h/2 );
        

        // //~ glNormal3f(-1, 0, 0);// LEFT
        // glNormal3f(b*h/face_norm, -l*h/face_norm, -l*b/face_norm);
        // glVertex3f(  0,  b/2,  h/2 );
        // glVertex3f( 0, -b/2, -h/2 );
        // glVertex3f(  -l/2,  b/2, -h/2 );
        
        
        // // glColor4f(1,0,1,1);
        // glNormal3f(0, -1, 0);// TOP
        // glVertex3f(  l/2,  b/2, -h/2 );
        // glVertex3f(  0,  b/2,  h/2 );
        // glVertex3f( -l/2,  b/2, -h/2 );
        

  glEnd();
}


void drawCubeWireframe(){
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS); 
    // glNormal3d(0, 0, -1);//Front
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    
    //~ glNormal3d(0, 0, -1); // Back
    glVertex3f( -0.5, -0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f(  0.5, -0.5, -0.5 ); 
     
    // Purple side - RIGHT
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    
    // Green side - LEFT
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    
    // Blue side - TOP
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    
    // Red side - BOTTOM
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
}

void drawCuboidSolid(float l, float b, float h){
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
    // glColor4f(1,0,0,1);
    glNormal3f(0, 0, 1);// Front
    glVertex3f(  l/2, -b/2, h/2 );
    glVertex3f(  l/2,  b/2, h/2 );
    glVertex3f( -l/2,  b/2, h/2 );
    glVertex3f( -l/2, -b/2, h/2 );
    
    // glColor4f(0,1,0,1);
    glNormal3f(0, 0, -1); // Back
    glVertex3f( -l/2, -b/2, -h/2 );
    glVertex3f( -l/2,  b/2, -h/2 );
    glVertex3f(  l/2,  b/2, -h/2 );
    glVertex3f(  l/2, -b/2, -h/2 );   
    
    // glColor4f(0,0,1,1);
    glNormal3f(1, 0, 0);// RIGHT
    glVertex3f( l/2, -b/2, -h/2 );
    glVertex3f( l/2,  b/2, -h/2 );
    glVertex3f( l/2,  b/2,  h/2 );
    glVertex3f( l/2, -b/2,  h/2 );
    
    // glColor4f(1,1,0,1);
    glNormal3f(-1, 0, 0);// LEFT
    glVertex3f( -l/2, -b/2,  h/2 );
    glVertex3f( -l/2,  b/2,  h/2 );
    glVertex3f( -l/2,  b/2, -h/2 );
    glVertex3f( -l/2, -b/2, -h/2 );
  
    // glColor4f(1,0,1,1);
    glNormal3f(0, 1, 0);// TOP
    glVertex3f(  l/2,  b/2,  h/2 );
    glVertex3f(  l/2,  b/2, -h/2 );
    glVertex3f( -l/2,  b/2, -h/2 );
    glVertex3f( -l/2,  b/2,  h/2 );
  
    // glColor4f(0,1,1,1);
    glNormal3f(0, -1, 0);// BOTTOM
    glVertex3f(  l/2, -b/2, -h/2 );
    glVertex3f(  l/2, -b/2,  h/2 );
    glVertex3f( -l/2, -b/2,  h/2 );
    glVertex3f( -l/2, -b/2, -h/2 );
  glEnd();
}

void drawSphere(float r, float res){
	for(int j=0; j<res; j++){
		for(int i=0; i<res; i++){
			glBegin(GL_QUADS);
				glNormal3f( sin(i*2*PI/res)*sin(j*PI/res),  cos(i*PI*2/res)*sin(j*PI/res), cos(j*PI/res) );
			    glVertex3f( r*sin(i*2*PI/res)*sin(j*PI/res),  r*cos(i*PI*2/res)*sin(j*PI/res), r*cos(j*PI/res) );
			    glNormal3f( sin((i+1)*2*PI/res)*sin(j*PI/res),  cos((i+1)*2*PI/res)*sin(j*PI/res), cos(j*PI/res) );
			    glVertex3f( r*sin((i+1)*2*PI/res)*sin(j*PI/res),  r*cos((i+1)*2*PI/res)*sin(j*PI/res), r*cos(j*PI/res) );
			    glNormal3f( sin((i+1)*2*PI/res)*sin((j+1)*PI/res),  cos((i+1)*2*PI/res)*sin((j+1)*PI/res), cos((j+1)*PI/res) );
			    glVertex3f( r*sin((i+1)*2*PI/res)*sin((j+1)*PI/res),  r*cos((i+1)*2*PI/res)*sin((j+1)*PI/res), r*cos((j+1)*PI/res) );
			    glNormal3f( sin(i*2*PI/res)*sin((j+1)*PI/res),  cos(i*2*PI/res)*sin((j+1)*PI/res), cos((j+1)*PI/res) );
			    glVertex3f( r*sin(i*2*PI/res)*sin((j+1)*PI/res),  r*cos(i*2*PI/res)*sin((j+1)*PI/res), r*cos((j+1)*PI/res) );
			glEnd();
		}
	}
}
void drawSphereInwards(float r, float res){
	for(int j=0; j<res; j++){
		for(int i=0; i<res; i++){
			glBegin(GL_QUADS);
							    
			    glNormal3f( -sin(i*2*PI/res)*sin((j+1)*PI/res),  -cos(i*2*PI/res)*sin((j+1)*PI/res), -cos((j+1)*PI/res) );
			    glVertex3f( r*sin(i*2*PI/res)*sin((j+1)*PI/res),  r*cos(i*2*PI/res)*sin((j+1)*PI/res), r*cos((j+1)*PI/res) );
			    
			    glNormal3f( -sin((i+1)*2*PI/res)*sin((j+1)*PI/res),  -cos((i+1)*2*PI/res)*sin((j+1)*PI/res), -cos((j+1)*PI/res) );
			    glVertex3f( r*sin((i+1)*2*PI/res)*sin((j+1)*PI/res),  r*cos((i+1)*2*PI/res)*sin((j+1)*PI/res), r*cos((j+1)*PI/res) );
			    
			    glNormal3f( -sin((i+1)*2*PI/res)*sin(j*PI/res),  -cos((i+1)*2*PI/res)*sin(j*PI/res), -cos(j*PI/res) );
			    glVertex3f( r*sin((i+1)*2*PI/res)*sin(j*PI/res),  r*cos((i+1)*2*PI/res)*sin(j*PI/res), r*cos(j*PI/res) );
			    
			    glNormal3f( -sin(i*2*PI/res)*sin(j*PI/res),  -cos(i*PI*2/res)*sin(j*PI/res), -cos(j*PI/res) );
			    glVertex3f( r*sin(i*2*PI/res)*sin(j*PI/res),  r*cos(i*PI*2/res)*sin(j*PI/res), r*cos(j*PI/res) );
			glEnd();
		}
	}
}


void drawCylinder(float r, float h, float res){
	for(int i=0; i<res; i++){
		glBegin(GL_TRIANGLES);
			glNormal3f(0, 0, 1);// Front
		    glVertex3f( 0, 0, h/2 );
		    glVertex3f( r*sin((i+1)*2*PI/res),  r*cos((i+1)*2*PI/res), h/2 );
		    glVertex3f( r*sin(i*2*PI/res),  r*cos(i*PI*2/res), h/2 );
		    
		    glNormal3f(0, 0, -1);// Front
		    glVertex3f( 0, 0, -h/2 );
		    glVertex3f( r*sin(i*2*PI/res),  r*cos(i*2*PI/res), -h/2 );
		    glVertex3f( r*sin((i+1)*2*PI/res),  r*cos((i+1)*2*PI/res), -h/2 );
		glEnd();
		glBegin(GL_QUADS);
			//~ glNormal3f((r*sin(i*2*PI/res)+r*sin((i+1)*2*PI/res))/2, (r*cos(i*2*PI/res)+r*cos((i+1)*2*PI/res))/2, 0);// Front
		    glNormal3f( sin(i*2*PI/res),  cos(i*PI*2/res), 0 );
		    glVertex3f( r*sin(i*2*PI/res),  r*cos(i*PI*2/res), h/2 );
		    glNormal3f( sin((i+1)*2*PI/res),  cos((i+1)*2*PI/res), 0 );
		    glVertex3f( r*sin((i+1)*2*PI/res),  r*cos((i+1)*2*PI/res), h/2 );
		    glNormal3f( sin((i+1)*2*PI/res),  cos((i+1)*2*PI/res), 0 );
		    glVertex3f( r*sin((i+1)*2*PI/res),  r*cos((i+1)*2*PI/res), -h/2 );
		    glNormal3f( sin(i*2*PI/res),  cos(i*2*PI/res), 0 );
		    glVertex3f( r*sin(i*2*PI/res),  r*cos(i*2*PI/res), -h/2 );
		glEnd();
	}
}

void drawCuboidEdgeYd(float l, float b, float h){
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
    // glColor4f(1,0,0,1);
    glNormal3f(0, 0, 1);// Front
    glVertex3f(  l/2, -b, h/2 );
    glVertex3f(  l/2,  0, h/2 );
    glVertex3f( -l/2,  0, h/2 );
    glVertex3f( -l/2, -b, h/2 );
    
    // glColor4f(0,1,0,1);
    glNormal3f(0, 0, -1); // Back
    glVertex3f( -l/2, -b, -h/2 );
    glVertex3f( -l/2,  0, -h/2 );
    glVertex3f(  l/2,  0, -h/2 );
    glVertex3f(  l/2, -b, -h/2 );   
    
    // glColor4f(0,0,1,1);
    glNormal3f(1, 0, 0);// RIGHT
    glVertex3f( l/2, -b, -h/2 );
    glVertex3f( l/2,  0, -h/2 );
    glVertex3f( l/2,  0,  h/2 );
    glVertex3f( l/2, -b,  h/2 );
    
    // glColor4f(1,1,0,1);
    glNormal3f(-1, 0, 0);// LEFT
    glVertex3f( -l/2, -b,  h/2 );
    glVertex3f( -l/2,  0,  h/2 );
    glVertex3f( -l/2,  0, -h/2 );
    glVertex3f( -l/2, -b, -h/2 );
  
    // glColor4f(1,0,1,1);
    glNormal3f(0, 1, 0);// TOP
    glVertex3f(  l/2,  0,  h/2 );
    glVertex3f(  l/2,  0, -h/2 );
    glVertex3f( -l/2,  0, -h/2 );
    glVertex3f( -l/2,  0,  h/2 );
  
    // glColor4f(0,1,1,1);
    glNormal3f(0, -1, 0);// BOTTOM
    glVertex3f(  l/2, -b, -h/2 );
    glVertex3f(  l/2, -b,  h/2 );
    glVertex3f( -l/2, -b,  h/2 );
    glVertex3f( -l/2, -b, -h/2 );
  glEnd();
}

void drawPrism(float l, float b, float h ){
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLES);
    // glColor4f(1,0,0,1);
    glNormal3f(0, 0, 1);// Front
    glVertex3f(  l/2, -b, h/2 );
    glVertex3f(  l/2,  0, h/2 );
    glVertex3f( -l/2,  0, h/2 );
    //~ glVertex3f( -l/2, -b, h/2 );
    
    // glColor4f(0,1,0,1);
    glNormal3f(0, 0, -1); // Back
    //~ glVertex3f( -l/2, -b, -h/2 );
    glVertex3f( -l/2,  0, -h/2 );
    glVertex3f(  l/2,  0, -h/2 );
    glVertex3f(  l/2, -b, -h/2 );   

    glEnd();
    glBegin(GL_QUADS);
    //~ // glColor4f(0,0,1,1);
    glNormal3f(1, 0, 0);// RIGHT
    glVertex3f( l/2, -b, -h/2 );
    glVertex3f( l/2,  0, -h/2 );
    glVertex3f( l/2,  0,  h/2 );
    glVertex3f( l/2, -b,  h/2 );
    
    // glColor4f(1,1,0,1);
    glNormal3f(-b/sqrt(l*l+b*b), -l/sqrt(l*l+b*b), 0);// LEFT
    glVertex3f( l/2, -b,  h/2 );
    glVertex3f( -l/2,  0,  h/2 );
    glVertex3f( -l/2,  0, -h/2 );
    glVertex3f( l/2, -b, -h/2 );
  
    //~ // glColor4f(1,0,1,1);
    glNormal3f(0, 1, 0);// TOP
    glVertex3f(  l/2,  0,  h/2 );
    glVertex3f(  l/2,  0, -h/2 );
    glVertex3f( -l/2,  0, -h/2 );
    glVertex3f( -l/2,  0,  h/2 );
  
    // glColor4f(0,1,1,1);
    //~ glNormal3f(0, -1, 0);// BOTTOM
    //~ glVertex3f(  l/2, -b, -h/2 );
    //~ glVertex3f(  l/2, -b,  h/2 );
    //~ glVertex3f( -l/2, -b,  h/2 );
    //~ glVertex3f( -l/2, -b, -h/2 );
	glEnd();
}
