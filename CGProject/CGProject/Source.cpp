// Press f5 to Play and SpaceBar to Quickjump
// U Can use arrow key also for marginal movement. ;)
// btw, u may need to update image location to run successfuly....

#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include "imageloader.h"

using namespace std;

GLuint _textureId;

bool checkGravity = true;
bool checkPilar = true;

float birdx = 100;
float birdy = 255;

float X = 0.0;
float Y = 0.0;
float p1x = 0.0;
float p2x = 0.0;
float p3x = 0.0;
float p4x = 0.0;
float p5x = 0.0;


float pilar1UpX = 200;
float pilar1UpY = 450;
float pilar1DwnX = 200;
float pilar1DwnY = 60;

float pilar4UpX = 440;
float pilar4UpY = 480;
float pilar4DwnX = 440;
float pilar4DwnY = 0;


//Update Pilar position
void pilarUpdate()
{
	p1x -= 0.03;
	p2x -= 0.03;
	p3x -= 0.03;
	p4x -= 0.03;
	p5x -= 0.03;

	glutPostRedisplay();
	if (p1x <= -250)
	{
		p1x = 250;
		glutPostRedisplay();
	}

	glutPostRedisplay();
	if (p2x <= -280)
	{
		p2x = 280;
		glutPostRedisplay();
	}

	glutPostRedisplay();
	if (p3x <= -360)
	{
		p3x = 360;
		glutPostRedisplay();
	}

	glutPostRedisplay();
	if (p4x <= -400)
	{
		p4x = 440;
		glutPostRedisplay();
	}

	glutPostRedisplay();
	if (p5x <= -520)
	{
		p5x = 520;
		glutPostRedisplay();
	}


	if (checkPilar)
	{
		pilar1UpY -= 0.002;
		pilar1DwnY += 0.002;
		//Distance between two pilar is fixed ....
		if ((pilar1UpY - pilar1DwnY) <= 350)
		{
			checkPilar = false;
			glutPostRedisplay();
		}
	}
	pilar4UpY -= 0.002;
	pilar4DwnY += 0.002;
	glutPostRedisplay();
}


void gravity()
{
	if (checkGravity)
	{
		Y -= 0.04;
		glutPostRedisplay();

		// When the Bird reaches to ground flying stops....
		if (Y <= -200)
		{
			checkPilar = true;
			Y = 0.0;
			glutPostRedisplay();
		}
		glutPostRedisplay();
	}
}




void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glNormal3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex3f(0.0, -0.55, 0.0);

	glTexCoord2f(1, 0);
	glVertex3f(15, -0.55, 0.0);


	glTexCoord2f(1, 1);
	glVertex3f(15, 6.0, 0.0);

	glTexCoord2f(0, 1);
	glVertex3f(0.0, 6.0, 0.0);

	glEnd();


	//ground
	glColor3f(0.91, 0.0, 0.65);
	glBegin(GL_QUADS);
		glVertex2i(0, 0);
		glVertex2i(750, 0);
		glVertex2i(750, 50);
		glVertex2i(0, 50);
	glEnd();

	//up
	glColor3f(0.91, 0.0, 0.65);
	glBegin(GL_QUADS);
	glVertex2i(0, 450);
	glVertex2i(750, 750);
	glVertex2i(750, 400);
	glVertex2i(0, 400);
	glEnd();

	//up-ground
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
		glVertex2i(0, 50);
		glVertex2i(750, 50);
		glVertex2i(750, 60);
		glVertex2i(0, 60);
	glEnd();

	glPushMatrix();
	glTranslatef(X, Y, 0.0);
	//bird
		glColor3f(0.196078, 0.6, 0.8);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2i(birdx, birdy);   // 100 255
	
			glTexCoord2f(1.0, 0.0);
			glVertex2i(birdx+25, birdy);   // 125 255
	
			glTexCoord2f(1.0, 1.0);
			glVertex2i(birdx+25, birdy+40);  // 125 290
	
			glTexCoord2f(0.0, 1.0);
			glVertex2i(birdx, birdy+40);   // 100 290
		glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(p1x, 0.0, 0.0);
		//piler 1(up_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
			glVertex2i(pilar1UpX, pilar1UpY);				// glVertex2i(200, 450);               
			glVertex2i(pilar1UpX + 30, pilar1UpY);			// glVertex2i(230, 450);
			glVertex2i(pilar1UpX + 30, pilar1UpY - 100);    // glVertex2i(230, 350);
			glVertex2i(pilar1UpX, pilar1UpY - 100);			// glVertex2i(200, 350);
		glEnd();

		//piler 1(down_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
			glVertex2i(pilar1DwnX, 0);				//glVertex2i(200, 60);
			glVertex2i(pilar1DwnX+30, 0);			//glVertex2i(230, 60);
			glVertex2i(pilar1DwnX+30, pilar1DwnY+160);		//glVertex2i(230, 220);
			glVertex2i(pilar1DwnX, pilar1DwnY+160);			//glVertex2i(200, 220);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p2x, 0.0, 0.0);
		//piler 2(up_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
			glVertex2i(280, 450);				//glVertex2i(280, 450);
			glVertex2i(310, 450);			// glVertex2i(310, 450);
			glVertex2i(310, 370);			// glVertex2i(310, 370);
			glVertex2i(280, 370);			// glVertex2i(280, 370);
		glEnd();

		//piler 2(down_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
			glVertex2i(280, 60);			//	glVertex2i(280, 60);
			glVertex2i(310, 60);		// glVertex2i(310, 60);
			glVertex2i(310, 170);	// glVertex2i(310, 170);
			glVertex2i(280, 170);		//glVertex2i(280, 170);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p3x, 0.0, 0.0);
		//piler 3(up_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(360, 450);
		glVertex2i(390, 450);
		glVertex2i(390, 350);
		glVertex2i(360, 350);
		glEnd();

		//piler 3(down_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(360, 0);
		glVertex2i(390, 0);
		glVertex2i(390, 220);
		glVertex2i(360, 220);
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p4x, 0.0, 0.0);
		//piler 4(up_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(pilar4UpX, pilar4UpY);				//
		glVertex2i(pilar4UpX + 30, pilar4UpY);			//
		glVertex2i(pilar4UpX + 30, pilar4UpY - 150);	//
		glVertex2i(pilar4UpX, pilar4UpY - 150);			//
		glEnd();

		//piler 4(down_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(pilar4DwnX, pilar4DwnY);				//	
		glVertex2i(pilar4DwnX + 30, pilar4DwnY);		// 
		glVertex2i(pilar4DwnX + 30, pilar4DwnY + 110);	// 
		glVertex2i(pilar4DwnX, pilar4DwnY + 110);		//
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p5x, 0.0, 0.0);
		//piler 5(up_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(520, 450);
		glVertex2i(550, 450);
		glVertex2i(550, 300);
		glVertex2i(520, 300);
		glEnd();

		//piler 5(down_part)
		glColor3f(0.0, 0.5, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(520, 0);
		glVertex2i(550, 0);
		glVertex2i(550, 170);
		glVertex2i(520, 170);
		glEnd();
	glPopMatrix();

	glutSwapBuffers();

	glFlush(); 

	gravity();

	pilarUpdate();
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void lightSetting()
{

	GLfloat ambientIntensity[4] = { 0.6, 0.6, 0.6, 1.0 };

	GLfloat position[4] = { 0.0, 1.0, 0.0, 0.0 };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientIntensity);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

//SpaceBar
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		Y = Y + 20.0;
		//checkGravity = true;
		glutPostRedisplay();
	case 's':
		checkPilar = true;
		pilar1UpY = 450;
		pilar1DwnY = 60;
		pilar4UpY = 450;
		pilar4DwnY = 0;
		glutPostRedisplay();
	case ' ':
		Y = Y + 20.0;
		checkGravity = true;
		glutPostRedisplay();

	}
}

//Arrow Key
void specialKeypress(int key, int x, int y) 
{
	if (key == GLUT_KEY_RIGHT)
	{
		X += 6.0;
		glutPostRedisplay();
	}
	else if (key == GLUT_KEY_LEFT)
	{
		X -= 6.0;
		glutPostRedisplay();
	}
	else if (key == GLUT_KEY_UP)
	{
		Y += 6.0;
		glutPostRedisplay();
	}
	else if (key == GLUT_KEY_DOWN)
	{
		Y -= 6.0;
		glutPostRedisplay();
	}
}

void Initialize() {
	//sky blue
	glClearColor(0.196078, 0.6, 0.8, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 450, 0, 450);
	//Update Image location below..................
	Image* image = loadBMP("C:\\Users\\DIU\\Documents\\visual studio 2013\\Projects\\CGProject\\CGProject\\Images\\bird.bmp");

	_textureId = loadTexture(image);

	delete image;

}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(750, 450);
	glutInitWindowPosition(400, 200);
	glutCreateWindow("Flappy Bird");
	Initialize();
	lightSetting();
	glutDisplayFunc(Draw);
	glutIdleFunc(Draw);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(specialKeypress); 
	glutMainLoop();
	return 0;
}