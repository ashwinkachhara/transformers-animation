=================================================
CS475 Computer Graphics | Assignment 2.3
=================================================

Ashwin Kachhara, 10D070048
Sumeet Fefar, 10D070001

Link to YouTube Video: https://www.youtube.com/watch?v=wW7zNaYeoLY

1. Compile & Run:
	in Linux Terminal,
	'make' to compile
	'make clean' to remove generated binaries
	'./transformer' to run program
	
2. Keyboard Mappings
	
	WINDOW
	'Esc' 				=> Close Window
	
	MOVEMENT
	'<-'				=> Move Left
	'->'				=> Move Right
	'Up Arrow'			=> Move Fwd
	'Down Arrow'			=> Move Back
	'E'				=> Move Up
	'C'				=> Move Down
	'R' & 'T'			=> Change Yaw
	'F' & 'G'			=> Change Pitch
	'V' & 'B' 			=> Change Roll
	'Tab"				=> Transform/Untransform
	
	CAMERA
	'1'				=> Global Camera
	'2'				=> Point-of-View Camera
	'3'				=> Vehicle-Following Camera
	
	In CAMERA mode 1
	Change Viewpoint by
	'W', 'A', 'S', 'D'
	
	MODES
	'4'				=> Toggles between  
					MODE_FREE - Free roam mode 
					MODE_RECORD - Record keyframes in this mode 
							by pressing SPACE. Saved in 
							keyframes.txt file
					MODE_PLAYBACK - Play saved keyframes in this
							mode by pressing SPACE. Read
							from keyframes-play.txt

