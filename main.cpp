#include <iostream>
#include<stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<string.h>
//#include <conio.h>
#include <stdio.h>
//#include <windows.h>
//#include<mmsystem.h>
#include<SOIL/SOIL.h>
GLuint tex_2d1;
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
static float r,g,b;
int flag=0;
int start=0;
void drawsoldier();
void image(char,int,int,int,int);
void drawsoldierindian();
int x1,x2,y1,y2;
int option;
int gunclick=0;
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
}




void myinit(void)
{
glClearColor( 0.196078, 0.6, 0.8,0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,640.0,0.0,400.0);
}
int changedress=0;
int onMouse=0,faceclick=0,bodyclick=0,px,py;


void keyboard(unsigned char key,int x, int y)
{
   if(key==13){

        start=1;
       glClearColor( 0.196078, 0.6, 0.8,0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

    if (key==27)
        exit(0);

}

void image(char* str, int x1,int x2,int y1, int y2)
{
     glMatrixMode(GL_PROJECTION);
                    glEnable(GL_TEXTURE_2D);
                    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                    tex_2d1 = SOIL_load_OGL_texture
                    (
                        str,
                        SOIL_LOAD_AUTO,
                        SOIL_CREATE_NEW_ID,
                        SOIL_FLAG_COMPRESS_TO_DXT
                    );
                    glBindTexture(GL_TEXTURE_2D, tex_2d1);
                    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
                    glBegin(GL_POLYGON);
                    glTexCoord2f(1.0, 1.0);
                    glVertex2f(x2,y2);
                    glTexCoord2f(0.0, 1.0);
                    glVertex2f(x1,y2);
                    glTexCoord2f(0.0, 0.0);
                    glVertex2f(x1,y1);
                    glTexCoord2f(1.0, 0.0);
                    glVertex2f(x2,y1);
                    glEnd();
                    glDisable(GL_TEXTURE_2D);
                    glutSwapBuffers();
                    glFlush();
}



void mouseClicks(int button, int state, int x, int y) {
int legclick=0;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        //r=1.0;
        //g=0.0;
        //b=0.0;
        //drawsoldierindian(r,g,b);
        px=x;
        py=y;
        printf("X:%d\t",px);
        printf("Y:%d\n",py);

//INDIAN HEAD
       if(px>=534 && px<=745 && py>=119 && py<=250 && option==2)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="IndianFlag.png";
                          image(str,400,650,400,250);
                }
        }
//INDIAN BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==2)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                   char str[]="IndiaFacts.PNG";

                    image(str,0,200,400,0);
                }
        }
//INDIAN PANCHE TOUCH
          else if(px>=534 && px<=745 && py>=578 && py<=728 && option==2)
            {

                legclick+=1;
                if(legclick%2!=0)
                {
                   char str[]="IndianMap.png";
                    image(str,400,650,220,0);
                }
            }

//AMERICAN HEAD
  if(px>=534 && px<=745 && py>=119 && py<=250 && option==3)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="USAFlag.png";
                    image(str,400,650,400,250);
                }
        }
//AMERICAN BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==3)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                   char str[]="AmericanFacts.PNG";
                   image(str,0,200,400,0);
                }
        }
//AMERICAN LEG TOUCH
              else if(px>=534 && px<=745 && py>=578 && py<=728 && option==3)
            {

                legclick+=1;
                if(legclick%2!=0)
                {
                   char str[]="USAMap.png";
                    image(str,390,640,220,0);
                }
            }
//Chinese HEAD
  if(px>=534 && px<=745 && py>=119 && py<=250 && option==4)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="ChinaFlag.png";

                          image(str,400,650,400,250);
                }
        }
//CHINESE BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==4)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                   char str[]="ChinaFacts.PNG";
                     image(str,0,210,400,0);

                }
        }
//CHINESE LEG TOUCH
          else if(px>=534 && px<=745 && py>=578 && py<=728 && option==4)
            {

                legclick+=1;
                if(legclick%2!=0)
                {
                   char str[]="ChinaMap.png";
                    image(str,400,640,190,0);
                }
            }


//RUSSIAN HEAD
 if(px>=534 && px<=745 && py>=119 && py<=250 && option==5)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="RussiaFlag.png";

                          image(str,400,650,400,250);
                }
        }
//RUSSIAN BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==5)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                   char str[]="RussiaFacts.PNG";
                     image(str,0,210,400,0);

                }
        }
//RUSSIAN LEG TOUCH
          else if(px>=534 && px<=745 && py>=578 && py<=728 && option==5)
            {

                legclick+=1;
                if(legclick%2!=0)
                {
                   char str[]="RussiaMap.png";
                    image(str,400,640,190,0);
                }
            }

//INDIAN SOLDIER HEAD
  if(px>=534 && px<=745 && py>=119 && py<=250 && option==21)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="IndianWars.png";
                        image(str,0,230,400,0);
                }
        }
//INDIAN SOLDIER BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==21)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                     char str[]="IndianArmedForces.png";
                    image(str,450,650,190,0);
                }
        }

//INDIAN GUN TOUCH
 else if(px>=875 && px<=1001 && py>=100 && py<=519 && option==21)
            {

                gunclick+=1;
                if(gunclick%2!=0)
                {
                   char str[]="IndiaArsenal.png";
                    image(str,450,640,400,190);
                }
        }
//AMERICAN SOLDIER HEAD
  if(px>=534 && px<=745 && py>=119 && py<=250 && option==31)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="AmericanWars.png";
                        image(str,0,230,400,0);
                }
        }
//AMERICAN SOLDIER BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==31)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                   char str[]="USAArmedForces.png";
                    image(str,450,645,170,0);
                }
        }
//AMERICAN SOLDIER LEG TOUCH

//AMERICAN GUN TOUCH
 else if(px>=875 && px<=1001 && py>=100 && py<=519 && option==31)
            {

                gunclick+=1;
                if(gunclick%2!=0)
                {
                   char str[]="AmericanArsenal.png";
                    image(str,450,645,400,170);
                }
        }
//CHINESE SOLDIER HEAD
  if(px>=534 && px<=745 && py>=119 && py<=250 && option==41)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="ChinaWars.PNG";
                        image(str,0,230,400,0);
                }
        }
//CHINESE SOLDIER BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==41)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                   char str[]="ChineseArmedForces.png";
                    image(str,450,650,170,0);
                }
        }
//CHINESE SOLDIER LEG TOUCH

//CHINESE GUN TOUCH
 else if(px>=875 && px<=1001 && py>=100 && py<=519 && option==41)
            {

                gunclick+=1;
                if(gunclick%2!=0)
                {
                   char str[]="ChinaArsenal.png";
                    image(str,450,645,400,170);
                }
        }

//RUSSIAN SOLDIER HEAD
  if(px>=534 && px<=745 && py>=119 && py<=250 && option==51)
        {
            faceclick+=1;
                if(faceclick%2!=0)
                {
                    char str[]="RussiaWars.PNG";
                        image(str,0,230,400,0);
                }
        }
//RUSSIAN SOLDIER BODY TOUCH
        else if(px>=534 && px<=745 && py>=288 && py<=571 && option==51)
            {

                bodyclick+=1;
                if(bodyclick%2!=0)
                {
                   char str[]="RussianArmedForces.png";
                    image(str,450,650,170,0);
                }
        }
//RUSSIAN SOLDIER LEG TOUCH

//RUSSIAN GUN TOUCH
 else if(px>=875 && px<=1001 && py>=100 && py<=519 && option==51)
            {

                gunclick+=1;
                if(gunclick%2!=0)
                {
                   char str[]="RussiaArsenal.png";
                    image(str,450,645,400,170);
                }


            }
    }
}

void createMenu(void){

  //  int glut_menu[13];
//

    submenu_id = glutCreateMenu(menu);
   glutAddMenuEntry("Indian Normal",2);
   glutAddMenuEntry("Indian Soldier",21);
  glutAddMenuEntry("American Normal", 3);
 glutAddMenuEntry("American Soldier", 31);
 glutAddMenuEntry("Chinese Normal", 4);
  glutAddMenuEntry("Chinese Soldier", 41);
   glutAddMenuEntry("Russian Normal", 5);
  glutAddMenuEntry("Russian Soldier", 51);
   menu_id = glutCreateMenu(menu);
// glutCreateMenu(menu_select);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw InfoTron",submenu_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
   // glutAttachMenu(GLUT_LEFT_BUTTON);

}


void drawnormal(int r,int g,int b,int pr,int pg,int pb)
{
  //Face
glColor3f(0.858824,0.576471,0.439216);
glRecti(250,270,350,340);

//Mouth

int m1[]={270,300};
int m2[]={330,300};
int m3[]={320,280};
int m4[]={280,280};


//Mouth
glBegin(GL_QUADS);
glColor3f(0.0,0.0,0.0);
glVertex2iv(m1);
glVertex2iv(m2);
glVertex2iv(m3);
glVertex2iv(m4);
glEnd();

//Eyes
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex3f(280.0,330.0,0);
    glVertex3f(270.0,315.0,0);
    glVertex3f(290.0,315.0,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex3f(320.0,330.0,0);
    glVertex3f(310.0,315.0,0);
    glVertex3f(330.0,315.0,0);
    glEnd();

//Right Arm
//glColor3f(r,g,b);
//glRecti(290,250,310,270);
int q1[]={350,230};
int q2[]={390,200};
int q3[]={390,230};
int q4[]={350,250};

//Right Arm
glPushMatrix();
//glRotatef(30,1,0,0);
glBegin(GL_QUADS);
glColor3f(0.858824,0.576471,0.439216);
glVertex2iv(q1);
glVertex2iv(q2);
glVertex2iv(q3);
glVertex2iv(q4);
glEnd();
glPopMatrix();

int q5[]={250,230};
int q6[]={210,200};
int q7[]={210,230};
int q8[]={250,250};

//Left Arm
glBegin(GL_QUADS);
glColor3f(0.858824,0.576471,0.439216);
glVertex2iv(q5);
glVertex2iv(q6);
glVertex2iv(q7);
glVertex2iv(q8);
glEnd();


//NECK
glColor3f(0.858824,0.576471,0.439216);
glRecti(290,250,310,270);
//BODY
glColor3f(r,g,b);
glRecti(250,100,350,250);

//Shirt
glLineWidth(3.0);
glColor3f(0, 0,0);
glBegin(GL_LINES);
glVertex3f(295,230.0, 0.0);
glVertex3f(305,230, 0);
glVertex3f(295,220.0, 0.0);
glVertex3f(305,220, 0);
glVertex3f(295,210.0, 0.0);
glVertex3f(305,210, 0);
glEnd();


if(option==2) //If Indian
{
//Panche
glColor3f(1.0,1.0,1.0);
glRecti(250,100,350,20);
//Panche Line
glColor3f(1.0,2.0,0.0);
glRecti(250,50,350,30);
}
else{
//Right leg
glColor3f(pr,pg,pb);
glRecti(320,100,350,20);
//Left leg
glColor3f(pr,pg,pb);
glRecti(250,100,280,20);
}
//Right Shoe
 glBegin(GL_TRIANGLES);
    glColor3f(0.36,0.25,0.20);
    glVertex3f(335,20,0);
    glVertex3f(320.0,10.0,0);
    glVertex3f(350.0,10,0);
    glEnd();

//Left Shoe
 glBegin(GL_TRIANGLES);
    glColor3f(0.36,0.25,0.20);
    glVertex3f(265,20,0);
    glVertex3f(250.0,10.0,0);
    glVertex3f(280.0,10,0);
    glEnd();

glFlush();
}


void drawsoldier()
{
//glColor3f(1,0,0);
//glRecti(50,50,100,70);

//HAT
glColor3f(0,0,0);
glRecti(230,340,370,365);
  //Face
glColor3f(0.858824,0.576471,0.439216);
glRecti(250,270,350,340);

//Mouth

int m1[]={270,280};
int m2[]={330,280};
int m3[]={320,300};
int m4[]={280,300};

//Mouth
glBegin(GL_QUADS);
glColor3f(0.0,0.0,0.0);
glVertex2iv(m1);
glVertex2iv(m2);
glVertex2iv(m3);
glVertex2iv(m4);
glEnd();

glLineWidth(1.0);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(280,300.0, 0.0);
glVertex3f(280,280, 0);
glEnd();

glLineWidth(1.0);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(300,300.0, 0.0);
glVertex3f(300,280, 0);
glEnd();

glLineWidth(1.0);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f(320,300.0, 0.0);
glVertex3f(320,280, 0);
glEnd();

//Eyes
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0,0);
    glVertex3f(280.0,330.0,0);
    glVertex3f(270.0,315.0,0);
    glVertex3f(290.0,315.0,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0,0);
    glVertex3f(320.0,330.0,0);
    glVertex3f(310.0,315.0,0);
    glVertex3f(330.0,315.0,0);
    glEnd();
//GUN
glColor3f(0.59,0.41,0.31);
glRecti(410,205,470,225);

 glBegin(GL_TRIANGLES);
    glColor3f(0.59,0.41,0.31);
    glVertex3f(410,350.0,0);
    glVertex3f(410.0,225.0,0);
    glVertex3f(430.0,225.0,0);
    glEnd();
glColor3f(0.59,0.41,0.31);
glRecti(410,205,430,130);
 glBegin(GL_TRIANGLES);
    glColor3f(0.59,0.41,0.31);
    glVertex3f(430,160.0,0);
    glVertex3f(430.0,130.0,0);
    glVertex3f(455.0,130.0,0);
    glEnd();


//Right Arm
//glColor3f(1.0,0.4,1.0);
//glRecti(290,250,310,270);
int q1[]={350,230};
int q2[]={410,200};
int q3[]={410,230};
int q4[]={350,250};

//Right Arm
glBegin(GL_POLYGON);
glColor3f(r,g,b);
glVertex2iv(q1);
glVertex2iv(q2);
glVertex2iv(q3);
glVertex2iv(q4);
glEnd();


int q5[]={250,210};
int q6[]={240,150};
int q7[]={240,180};
int q8[]={250,250};

//Left Arm
glBegin(GL_QUADS);
glColor3f(0.0,0.0,0.0);
glVertex2iv(q5);
glVertex2iv(q6);
glVertex2iv(q7);
glVertex2iv(q8);
glEnd();


//NECK
glColor3f(0.858824,0.576471,0.439216);
glRecti(290,250,310,270);
//BODY
glColor3f(0.184314 ,0.309804,0.184314);
glRecti(250,100,350,250);

//Shirt
glLineWidth(3.0);
glColor3f(0, 0,0);
glBegin(GL_LINES);
glVertex3f(295,230.0, 0.0);
glVertex3f(305,230, 0);
glVertex3f(295,220.0, 0.0);
glVertex3f(305,220, 0);
glVertex3f(295,210.0, 0.0);
glVertex3f(305,210, 0);

glEnd();

//Right leg
glColor3f(0,0,0);
glRecti(320,100,350,20);
//Left leg
glColor3f(0,0,0);
glRecti(250,100,280,20);

//Right Shoe
 glBegin(GL_TRIANGLES);
    glColor3f(0.36,0.25,0.20);
    glVertex3f(335,20,0);
    glVertex3f(320.0,10.0,0);
    glVertex3f(350.0,10,0);
    glEnd();

//Left Shoe
 glBegin(GL_TRIANGLES);
    glColor3f(0.36,0.25,0.20);
    glVertex3f(265,20,0);
    glVertex3f(250.0,10.0,0);
    glVertex3f(280.0,10,0);
    glEnd();

glFlush();

}


void text(GLfloat x,GLfloat y,char * updateWord)
{
    int len,i;
    char menu[80];
    strcpy(menu,updateWord);
    len = strlen(updateWord);
    //glColor3f(1,0,0);
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0, 600, 0, 600 );
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    //glScalef(0.2,0.2,11);
    //glColor3f(1.0, 1.0, 0.0);
    for ( i = 0; i <len; ++i )
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, menu[i]);
    glPopMatrix();
    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}



void Polygon(int)
{
glClear(GL_COLOR_BUFFER_BIT);

if(value == 1){
    return; //glutPostRedisplay();
  }
else if(value == 2){
//Indian
    option=2;
    int rb=0,gb=0.2,bb=0;
    drawnormal(rb,gb,bb,0,0,0);
  }
else if(value ==21)
{
    option=21;
    drawsoldier();
}
  else if(value == 3){
    option=3;
    //American
    int rb=1,gb=1,bb=1;
    int rp=0,gp=0,bp=1;
   drawnormal(rb,gb,bb,rp,gp,bp);
  }
  else if(value ==31)
{
    //American
    option=31;
    drawsoldier();
}
  else if(value == 4){
    option=4;
    //Chinese
  int rb=1,gb=0,bb=0;
    int rp=0,gp=0,bp=0;
   drawnormal(rb,gb,bb,rp,gp,bp);
  }
  else if(value ==41)
{
    //Chinese
    option=41;
    drawsoldier();
}else if(value ==5){
    option=5;
    //Russian
     int rb=1,gb=0,bb=0;
    int rp=1,gp=1,bp=1;
   drawnormal(rb,gb,bb,rp,gp,bp);
}else if(value ==51)
{
    option=51;
    drawsoldier();
}

void glutSwapBuffers(void);
     glFlush();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
if(start==0)
{
    text(300,500,"INFOTRON");
    text(100,350,"Pranav Manjunath");
    text(450,350,"Preetham TY");
    text(100,330,"1PE16CS114");
    text(450,330,"1PE16CS119");

    text(100,100,"Press 'ENTER' and then Right Click to begin!    ");

}
if(start==1)
{

    Polygon(1);
}
}


int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(50,100);

//glutInitWindowSize(500,500);
glutCreateWindow("InfoTron In  Action");
myinit();
glutFullScreen();
createMenu();
//glutMouseFunc(mouseClicks);
glutKeyboardFunc(keyboard);
//glutDisplayFunc(drawindian);
glutDisplayFunc(display);

glutMainLoop();
}
