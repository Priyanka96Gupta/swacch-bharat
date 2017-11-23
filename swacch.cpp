#include<GL/freeglut.h>
#include<GL/freeglut_std.h>
#include<GL/freeglut_ext.h>
#include<GL/glu.h>
#include<stdio.h>
#include<GL/glut.h>
#include<time.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<unistd.h>
float i=0.0;//truck movement
int t=0;//for front page delay
int z=250;//for truck delay
float a=0.0;//fly movement
#define speed 50
int dirt=1;
float m=1.0;//cloud movement
float n=0.0,p=0.0,o=0.0,q=0.0;//stick movement
float s=0.0,v=0.0;//girl movement
float c=0.627,e=0.322 ,f=0.176 ;//color change
void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
}
void title()
{
     glColor3f(0.0,0.0,0.0);
     glRasterPos2f(480,450);
     declare("SCHOOL");
	 glRasterPos2f(150,350);
     declare("POND");

}
void title1()
{
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,700);
    glVertex2f(1100,700);
    glVertex2f(1100,0);
    glEnd();
	glColor3f(0.545,0.000,0.000);
	 glRasterPos2f(420,500);
	 declare("SWACHH BHARATH ABHIYAAN");
    glColor3f(0.0,0.0,0.0);
	 glRasterPos2f(400,640);
	 declare("THE OXFORD COLLEGE OF ENGINEERING");
	 glRasterPos2f(350,600);
	 declare("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	 glRasterPos2f(450,550);
	 declare("A MINI PROJECT ON");
	 glRasterPos2f(500,450);
	 declare("BY");
	 glRasterPos2f(430,400);
	 declare("PRIYANKA GUPTA    1OX14CS064");
	 glRasterPos2f(430,380);
	 declare("PRIYANKA SANU     1OX14CS065");
	 glRasterPos2f(430,360);
	 declare("PRIYANKA SURIYA   1OX14CS066");
	 glRasterPos2f(430,340);
	 declare("VAISHNAVI PATIL   1OX14CS104");
	 glRasterPos2f(500,200);
	 declare("GUIDE:");
	 glRasterPos2f(490,180);
	 declare("Ms.FLORANCE");
}
void draw_pixel(GLint cx, GLint cy)
{
    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
	glEnd();
}
void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}
void draw_object()
{
int l;
if(dirt==1)
{
//sky
glColor3f(0.529,0.808,0.980);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glColor3f(0.118,0.565,1.000);
glVertex2f(0,700);
glVertex2f(1100,700);
glColor3f(0.529,0.808,0.980);
glVertex2f(1100,450);
glEnd();
//sun
for(l=0;l<=35;l++)
{
		glColor3f(1.000,0.647,0.000);
		draw_circle(100,625,l);
}
//cloud1
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);
    }
for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}
//cloud2
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}
for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
}
//grass
glColor3f(0.000,1.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glColor3f(0.000,0.502,0.000);
glVertex2f(0,450);
glVertex2f(1100,450);
glColor3f(0.000,1.000,0.000);
glVertex2f(1100,160);
glEnd();
//footpath boundary
glColor3f(0.627,0.322,0.176);
glBegin(GL_POLYGON);
glVertex2f(0,260);
glVertex2f(0,270);
glVertex2f(1100,270);
glVertex2f(1100,260);
glEnd();
//footpath
glColor3f(0.871,0.722,0.529);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glColor3f(0.824,0.706,0.549);
glVertex2f(0,260);
glVertex2f(1100,260);
glColor3f(0.871,0.722,0.529);
glVertex2f(1100,160);
glEnd();
//road boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();
//road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();
//waste
glColor3f(0.824,0.412,0.118);
glBegin(GL_POLYGON);
glVertex2f(500,300);
glVertex2f(510,315);
glColor3f(0.0,0.0,0.0);
glVertex2f(515,320);
glVertex2f(525,312);
glColor3f(0.824,0.412,0.118);
glVertex2f(535,295);
//glVertex2f(484,293);
glEnd();
//leaves
glColor3f(0.000,0.392,0.000);
glBegin(GL_POLYGON);
glVertex2f(700,350);
glVertex2f(705,355);
glVertex2f(710,360);
glVertex2f(710,360);
glVertex2f(715,355);
glVertex2f(720,350);
glColor3f(0.0,1.0,0.0);
glVertex2f(715,345);
glVertex2f(710,340);
glVertex2f(710,340);
glVertex2f(705,345);
glEnd();
glColor3f(0.627,0.322,0.075);
glBegin(GL_POLYGON);
glVertex2f(400,350);
glVertex2f(405,355);
glVertex2f(410,360);
glVertex2f(410,360);
glVertex2f(415,355);
glVertex2f(420,350);
glColor3f(0.957,0.643,0.376);
glVertex2f(415,345);
glVertex2f(410,340);
glVertex2f(410,340);
glVertex2f(405,345);
glEnd();
glColor3f(0.627,0.322,0.075);
glBegin(GL_POLYGON);
glVertex2f(300,250);
glVertex2f(305,255);
glVertex2f(310,260);
glVertex2f(310,260);
glVertex2f(315,255);
glVertex2f(320,250);
glColor3f(0.957,0.643,0.376);
glVertex2f(315,245);
glVertex2f(310,240);
glVertex2f(310,240);
glVertex2f(305,245);
glEnd();
for(l=0;l<15;l++)
{
glColor3f(0.502,0.000,0.000);
draw_circle(25,430,l);
}
for(l=0;l<15;l++)
{
glColor3f(0.625,0.323,0.176);
draw_circle(35,430,l);
}
for(l=0;l<15;l++)
{
glColor3f(0.722,0.525,0.043);
draw_circle(35,440,l);
}
//sticks
glColor3f(0.957,0.643,0.376);
glBegin(GL_LINES);
glVertex2f(600,350);
glVertex2f(630,330);
glEnd();
glColor3f(0.957,0.643,0.376);
glBegin(GL_LINES);
glVertex2f(605,350);
glVertex2f(635,330);
glEnd();
glColor3f(0.957,0.643,0.376);
glBegin(GL_LINES);
glVertex2f(610,350);
glVertex2f(640,330);
glEnd();
glColor3f(0.957,0.643,0.376);
glBegin(GL_LINES);
glVertex2f(595,345);
glVertex2f(625,325);
glEnd();
//house1
glColor3f(1.000,0.078,0.576);
glBegin(GL_POLYGON);
glVertex2f(450,400);
glVertex2f(450,450);
glVertex2f(500,510);
glColor3f(1.000,0.412,0.706);
glVertex2f(570,450);
glVertex2f(570,390);
glEnd();
//roof
glColor3f(0.545,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(500,510);
glVertex2f(570,450);
glVertex2f(605,450);
glVertex2f(655,510);
glEnd();
//side wall
glColor3f(1.000,0.078,0.576);
glBegin(GL_POLYGON);
glVertex2f(570,390);
glVertex2f(570,450);
glColor3f(1.000,0.412,0.706);
glVertex2f(605,450);
glVertex2f(605,390);
glEnd();
//door
glColor3f(0.545,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(500,395);
glVertex2f(500,430);
glVertex2f(520,428);
glVertex2f(520,395);
glEnd();
// man1
for(l=0;l<=7;l++)
{
 glColor3f(0.0,0.0,0.0);
 draw_circle(515,270,l);
 }
 glColor3f(0.780,0.082,0.522);
 glBegin(GL_POLYGON);
 glVertex2f(507,265);
 glVertex2f(515,263);
 glVertex2f(522,260);
 glVertex2f(523,240);
 glVertex2f(507,245);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(507,265);
 glVertex2f(515,263);
 glVertex2f(522,260);
 glVertex2f(523,240);
 glVertex2f(507,245);
 glEnd();
 glColor3f(0.502,0.000,0.502);
 glBegin(GL_POLYGON);
 glVertex2f(507,245);
 glVertex2f(523,240);
 glVertex2f(523,225);
 glVertex2f(518,225);
 glVertex2f(518,242);
 glVertex2f(514,242);
 glVertex2f(514,225);
 glVertex2f(507,225);
 glEnd();
glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(507,245);
 glVertex2f(523,240);
 glVertex2f(523,225);
 glVertex2f(518,225);
 glVertex2f(514,242);
 glVertex2f(514,225);
 glVertex2f(507,225);
 glEnd();
//hands
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(523,257);
glVertex2f(523,253);
glVertex2f(530,251);
glVertex2f(532,254);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(523,257);
glVertex2f(523,253);
glVertex2f(530,251);
glVertex2f(532,254);
glEnd();
//pond
glColor3f(0.627,0.322,0.176);
glBegin(GL_POLYGON);
glVertex2f(25,350);
glVertex2f(25,375);
glVertex2f(50,400);
glVertex2f(75,410);
glVertex2f(100,420);
glVertex2f(200,420);
glVertex2f(225,410);
glVertex2f(250,405);
glColor3f(0.804,0.522,0.247);
glVertex2f(275,390);
glColor3f(0.690,0.878,0.902);
glVertex2f(300,375);
glVertex2f(310,350);
glVertex2f(300,320);
glVertex2f(275,300);
glVertex2f(250,295);
glVertex2f(225,290);
glVertex2f(200,285);
glVertex2f(175,280);
glVertex2f(150,280);
glVertex2f(125,280);
glVertex2f(100,290);
glVertex2f(75,300);
glVertex2f(50,310);
glEnd();
glColor3f(0.545,0.271,0.075);
glBegin(GL_POLYGON);
glVertex2f(30,400);
glVertex2f(25,397);
glColor3f(0.957,0.643,0.376);
glVertex2f(40,376);
glVertex2f(42,380);
glEnd();
//mleaves
for(l=0;l<=2;l++)
{
 glColor3f(0.000,0.392,0.000);
 draw_circle(400,320,l);
 }
 glColor3f(0.000,0.392,0.000);
 glBegin(GL_POLYGON);
 glVertex2f(397,320);
 glVertex2f(399,324);
 glVertex2f(400,328);
 glVertex2f(401,324);
 glVertex2f(403,320);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
 glVertex2f(400,318);
 glVertex2f(401,313);
 glEnd();
 for(l=0;l<=2;l++)
{
 glColor3f(0.000,0.392,0.000);
 draw_circle(380,320,l);
 }
 glColor3f(0.000,0.392,0.000);
 glBegin(GL_POLYGON);
 glVertex2f(377,320);
 glVertex2f(379,324);
 glVertex2f(380,328);
 glVertex2f(381,324);
 glVertex2f(383,320);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
 glVertex2f(380,318);
 glVertex2f(381,313);
 glEnd();
 for(l=0;l<=2;l++)
{
 glColor3f(0.000,0.392,0.000);
 draw_circle(378,310,l);
 }
 glColor3f(0.000,0.392,0.000);
 glBegin(GL_POLYGON);
 glVertex2f(375,310);
 glVertex2f(377,314);
 glVertex2f(378,318);
 glVertex2f(379,314);
 glVertex2f(380,310);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
 glVertex2f(378,308);
 glVertex2f(380,303);
 glEnd();
for(l=0;l<=2;l++)
{
 glColor3f(0.000,0.392,0.000);
 draw_circle(400,310,l);
 }
 glColor3f(0.000,0.392,0.000);
 glBegin(GL_POLYGON);
 glVertex2f(397,310);
 glVertex2f(399,314);
 glVertex2f(400,318);
 glVertex2f(401,314);
 glVertex2f(403,310);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
 glVertex2f(400,308);
 glVertex2f(403,303);
 glEnd();
 for(l=0;l<=2;l++)
{
 glColor3f(0.000,0.392,0.000);
 draw_circle(385,315,l);
 }
 glColor3f(0.000,0.392,0.000);
 glBegin(GL_POLYGON);
 glVertex2f(382,315);
 glVertex2f(383,319);
 glVertex2f(385,323);
 glVertex2f(387,319);
 glVertex2f(388,315);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
 glVertex2f(385,313);
 glVertex2f(388,310);
 glEnd();
 for(l=0;l<=2;l++)
{
 glColor3f(0.000,0.392,0.000);
 draw_circle(390,315,l);
 }
 glColor3f(0.000,0.392,0.000);
 glBegin(GL_POLYGON);
 glVertex2f(387,315);
 glVertex2f(389,319);
 glVertex2f(390,323);
 glVertex2f(391,319);
 glVertex2f(393,315);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
 glVertex2f(390,313);
 glVertex2f(393,310);
 glEnd();


//waste near trees
for(l=0;l<=15;l++)
{
{glColor3f(0.627,0.322,0.176);
draw_circle(800,300,l);
}
 if(l<10)
{glColor3f(0.412,0.412,0.412);
draw_circle(810,300,l);
}
if(l<12)
{glColor3f(0.412,0.412,0.412);
draw_circle(803,308,l);
}
}
glColor3f(0.502,0.502,0.000);
glBegin(GL_POLYGON);
glVertex2f(820,340);
glColor3f(0.000,0.392,0.000);
glVertex2f(830,350);
glVertex2f(835,345);
glVertex2f(845,365);
glColor3f(0.502,0.502,0.000);
glVertex2f(850,338);
glEnd();
glColor3f(0.000,0.000,0.000);
glBegin(GL_LINE_LOOP);
glVertex2f(820,340);
glColor3f(0.000,0.392,0.000);
glVertex2f(830,350);
glVertex2f(835,345);
glVertex2f(845,365);
glColor3f(0.502,0.502,0.000);
glVertex2f(850,338);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(825,345);
glVertex2f(833,350);
glVertex2f(840,355);
glVertex2f(845,343);
glVertex2f(847,340);
glEnd();
glColor3f(0.627,0.322,0.176);
glBegin(GL_POLYGON);
glVertex2f(945,350);
glVertex2f(955,360);
glVertex2f(965,370);
glVertex2f(970,370);
glVertex2f(975,380);
glVertex2f(980,370);
glVertex2f(990,353);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(960,365+a);
glVertex2f(965+a,365);
glVertex2f(970,370+a);
glVertex2f(975+a,355);
glVertex2f(980,367+a);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(102+a,320);
glVertex2f(105,350+a);
glVertex2f(108+a,340);
glVertex2f(100,350+a);
glVertex2f(99+a,325);
glVertex2f(200,400+a);
glVertex2f(206+a,402);
glVertex2f(196,399+a);
glVertex2f(204,404+a);
glEnd();
}
else
{
//sky
glColor3f(0.529,0.808,0.980);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glColor3f(0.118,0.565,1.000);
glVertex2f(0,700);
glVertex2f(1100,700);
glColor3f(0.529,0.808,0.980);
glVertex2f(1100,450);
glEnd();
//sun
for(l=0;l<=35;l++)
{
		glColor3f(1.000,0.647,0.000);
		draw_circle(100,625,l);
}
//cloud1
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);
    }
for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}
//cloud2
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}
for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
}
//grass
glColor3f(0.000,1.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glColor3f(0.000,0.502,0.000);
glVertex2f(0,450);
glVertex2f(1100,450);
glColor3f(0.000,1.000,0.000);
glVertex2f(1100,160);
glEnd();
//footpath boundary
glColor3f(0.627,0.322,0.176);
glBegin(GL_POLYGON);
glVertex2f(0,260);
glVertex2f(0,270);
glVertex2f(1100,270);
glVertex2f(1100,260);
glEnd();
//footpath
glColor3f(0.871,0.722,0.529);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glColor3f(0.824,0.706,0.549);
glVertex2f(0,260);
glVertex2f(1100,260);
glColor3f(0.871,0.722,0.529);
glVertex2f(1100,160);
glEnd();
//waste

glColor3f(0.412,0.412,0.412);
glBegin(GL_POLYGON);
glVertex2f(540,250);
glVertex2f(545,255);
glVertex2f(547,250);
glEnd();
glColor3f(0.412,0.412,0.412);
glBegin(GL_POLYGON);
glVertex2f(540,210);
glVertex2f(540,215);
glVertex2f(545,220);
glVertex2f(546,210);
glEnd();
glColor3f(0.412,0.412,0.412);
glBegin(GL_POLYGON);
glVertex2f(545,230);
glVertex2f(552,240);
glVertex2f(555,237);
glVertex2f(553,215);
glVertex2f(550,210);
glEnd();
glColor3f(0.412,0.412,0.412);
glBegin(GL_POLYGON);
glVertex2f(555,250);
glVertex2f(560,255);
glVertex2f(562,248);
glEnd();
glColor3f(0.412,0.412,0.412);
glBegin(GL_POLYGON);
glVertex2f(740,210);
glVertex2f(739,220);
glVertex2f(757,222);
glVertex2f(754,210);
glEnd();
// man1
for(l=0;l<=7;l++)
{
 glColor3f(0.0,0.0,0.0);
 draw_circle(515,270,l);
 }
 glColor3f(0.780,0.082,0.522);
 glBegin(GL_POLYGON);
 glVertex2f(507,265);
 glVertex2f(515,263);
 glVertex2f(522,260);
 glVertex2f(523,240);
 glVertex2f(507,245);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(507,265);
 glVertex2f(515,263);
 glVertex2f(522,260);
 glVertex2f(523,240);
 glVertex2f(507,245);
 glEnd();
 glColor3f(0.502,0.000,0.502);
 glBegin(GL_POLYGON);
 glVertex2f(507,245);
 glVertex2f(523,240);
 glVertex2f(523,225);
 glVertex2f(518,225);
 glVertex2f(518,242);
 glVertex2f(514,242);
 glVertex2f(514,225);
 glVertex2f(507,225);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(507,245);
 glVertex2f(523,240);
 glVertex2f(523,225);
 glVertex2f(518,225);
 glVertex2f(514,242);
 glVertex2f(514,225);
 glVertex2f(507,225);
 glEnd();
//hands
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(523,257);
glVertex2f(523,253);
glVertex2f(530,251);
glVertex2f(532,254);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(523,257);
glVertex2f(523,253);
glVertex2f(530,251);
glVertex2f(532,254);
glEnd();
//stick
glColor3f(0.545,0.271,0.075);
glBegin(GL_POLYGON);
glVertex2f(530+o,252+n);
glVertex2f(531+o,253+n);
glVertex2f(542+p,230+q);
glVertex2f(540+p,228+q);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(530+o,252+n);
glVertex2f(531+o,253+n);
glVertex2f(542+p,230+q);
glVertex2f(540+p,228+q);
glEnd();
glColor3f(0.545,0.271,0.075);
glBegin(GL_POLYGON);
glVertex2f(540+o,229+n);
glVertex2f(539+o,213+n);
glVertex2f(540+o,215+n);
glVertex2f(543+p,217+q);
glVertex2f(545+p,219+q);
glVertex2f(547+p,221+q);
glEnd();
glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(540+o,229+n);
glVertex2f(539+o,213+n);
glVertex2f(540+o,215+n);
glVertex2f(543+p,217+q);
glVertex2f(545+p,219+q);
glVertex2f(547+p,221+q);
glEnd();
//man2
for(l=0;l<=7;l++)
{
 glColor3f(0.0,0.0,0.0);
 draw_circle(775,270,l);
 }//shirt
 glColor3f(0.000,0.502,0.502);
 glBegin(GL_POLYGON);
 glVertex2f(767,265);
 glVertex2f(775,263);
 glVertex2f(782,260);
 glVertex2f(783,240);
 glVertex2f(767,245);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(767,265);
 glVertex2f(775,263);
 glVertex2f(782,260);
 glVertex2f(783,240);
 glVertex2f(767,245);
 glEnd();
 //pant
 glColor3f(0.741,0.718,0.420);
 glBegin(GL_POLYGON);
 glVertex2f(767,245);
 glVertex2f(783,240);
 glVertex2f(783,225);
 glVertex2f(778,225);
 glVertex2f(778,242);
 glVertex2f(774,242);
 glVertex2f(774,225);
 glVertex2f(767,225);
 glEnd();
 glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(767,245);
 glVertex2f(783,240);
 glVertex2f(783,225);
 glVertex2f(778,225);
 glVertex2f(774,242);
 glVertex2f(774,225);
 glVertex2f(767,225);
 glEnd();
//hands
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(783,257);
glVertex2f(783,253);
glVertex2f(790,251);
glVertex2f(792,254);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(783,257);
glVertex2f(783,253);
glVertex2f(790,251);
glVertex2f(792,254);
glEnd();
//stick
glColor3f(0.545,0.271,0.075);
glBegin(GL_POLYGON);
glVertex2f(790+o,252+n);
glVertex2f(791+o,253+n);
glVertex2f(802+p,225+q);
glVertex2f(800+p,223+q);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(790+o,252+n);
glVertex2f(791+o,253+n);
glVertex2f(802+p,225+q);
glVertex2f(800+p,223+q);
glEnd();
glColor3f(0.545,0.271,0.075);
glBegin(GL_POLYGON);
glVertex2f(801+o,229+n);
glVertex2f(799+o,213+n);
glVertex2f(800+o,215+n);
glVertex2f(803+p,217+q);
glVertex2f(805+p,219+q);
glVertex2f(807+p,221+q);
glEnd();
glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(801+o,229+n);
glVertex2f(799+o,213+n);
glVertex2f(800+o,215+n);
glVertex2f(803+p,217+q);
glVertex2f(805+p,219+q);
glVertex2f(807+p,221+q);
glEnd();
//house1
glColor3f(1.000,0.078,0.576);
glBegin(GL_POLYGON);
glVertex2f(450,400);
glVertex2f(450,450);
glVertex2f(500,510);
glColor3f(1.000,0.412,0.706);
glVertex2f(570,450);
glVertex2f(570,390);
glEnd();
//roof
glColor3f(0.545,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(500,510);
glVertex2f(570,450);
glVertex2f(605,450);
glVertex2f(655,510);
glEnd();
//side wall
glColor3f(1.000,0.078,0.576);
glBegin(GL_POLYGON);
glVertex2f(570,390);
glVertex2f(570,450);
glColor3f(1.000,0.412,0.706);
glVertex2f(605,450);
glVertex2f(605,390);
glEnd();
//door
glColor3f(0.545,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(500,395);
glVertex2f(500,430);
glVertex2f(520,428);
glVertex2f(520,395);
glEnd();
//girl1
for(l=0;l<=7;l++)
{
glColor3f(0.957,0.643,0.376);
draw_circle(450+s,410+v,l);
}//eyes
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(448+s,410+v);
glVertex2f(452+s,410+v);
glEnd();
//hair
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(450+s,421+v);
glVertex2f(440+s,417+v);
glVertex2f(440+s,408+v);
glVertex2f(443+s,408+v);
glVertex2f(443+s,417+v);
glVertex2f(450+s,417+v);
glVertex2f(457+s,408+v);
glVertex2f(459+s,417+v);
glEnd();
//shirt
glColor3f(1.000,1.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(450+s,403+v);
glVertex2f(440+s,401+v);
glVertex2f(440+s,382+v);
glVertex2f(460+s,380+v);
glVertex2f(460+s,399+v);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(450+s,403+v);
glVertex2f(440+s,401+v);
glVertex2f(440+s,382+v);
glVertex2f(460+s,380+v);
glVertex2f(460+s,399+v);
glEnd();
//skirt
glColor3f(0.282,0.239,0.545);
glBegin(GL_POLYGON);
glVertex2f(440+s,384+v);
glVertex2f(460+s,382+v);
glVertex2f(465+s,364+v);
glVertex2f(433+s,365+v);
glEnd();
//skirt
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(440+s,384+v);
glVertex2f(460+s,382+v);
glVertex2f(465+s,364+v);
glVertex2f(433+s,365+v);
glEnd();
//left leg
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(445+s,364+v);
glVertex2f(447+s,364+v);
glVertex2f(447+s,355+v);
glVertex2f(445+s,355+v);
glEnd();
//right leg
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(450+s,364+v);
glVertex2f(452+s,364+v);
glVertex2f(452+s,355+v);
glVertex2f(450+s,355+v);
glEnd();
//left leg
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(445+s,364+v);
glVertex2f(447+s,364+v);
glVertex2f(447+s,355+v);
glVertex2f(445+s,355+v);
glEnd();
//right leg
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(450+s,364+v);
glVertex2f(452+s,364+v);
glVertex2f(452+s,355+v);
glVertex2f(450+s,355+v);
glEnd();
//left hand
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(440+s,401+v);
glVertex2f(438+s,399+v);
glVertex2f(466+s,383+v);
glVertex2f(468+s,385+v);
glEnd();
//right hand
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(460+s,399+v);
glVertex2f(462+s,399+v);
glVertex2f(466+s,383+v);
glVertex2f(468+s,385+v);
glEnd();
//girl 2
for(l=0;l<=7;l++)
{
glColor3f(0.957,0.643,0.376);
draw_circle(500+s,410+v,l);
}//eyes
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(498+s,410+v);
glVertex2f(502+s,410+v);
glEnd();
//hair
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(500+s,421+v);
glVertex2f(490+s,417+v);
glVertex2f(490+s,408+v);
glVertex2f(493+s,408+v);
glVertex2f(493+s,417+v);
glVertex2f(500+s,417+v);
glVertex2f(507+s,408+v);
glVertex2f(509+s,417+v);
glEnd();
//shirt
glColor3f(0.690,0.769,0.871);
glBegin(GL_POLYGON);
glVertex2f(500+s,403+v);
glVertex2f(490+s,401+v);
glVertex2f(490+s,382+v);
glVertex2f(510+s,380+v);
glVertex2f(510+s,399+v);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(500+s,403+v);
glVertex2f(490+s,401+v);
glVertex2f(490+s,382+v);
glVertex2f(510+s,380+v);
glVertex2f(510+s,399+v);
glEnd();
//skirt
glColor3f(0.000,0.000,0.804);
glBegin(GL_POLYGON);
glVertex2f(490+s,384+v);
glVertex2f(510+s,382+v);
glVertex2f(515+s,364+v);
glVertex2f(485+s,365+v);
glEnd();
//skirt
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(490+s,384+v);
glVertex2f(510+s,382+v);
glVertex2f(515+s,364+v);
glVertex2f(485+s,365+v);
glEnd();
//left leg
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(497+s,364+v);
glVertex2f(499+s,364+v);
glVertex2f(499+s,355+v);
glVertex2f(497+s,355+v);
glEnd();
//right leg
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(501+s,364+v);
glVertex2f(503+s,364+v);
glVertex2f(503+s,355+v);
glVertex2f(501+s,355+v);
glEnd();
//left leg
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(497+s,364+v);
glVertex2f(499+s,364+v);
glVertex2f(499+s,355+v);
glVertex2f(497+s,355+v);
glEnd();
//right leg
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(501+s,364+v);
glVertex2f(503+s,364+v);
glVertex2f(503+s,355+v);
glVertex2f(501+s,355+v);
glEnd();
//left hand
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(490+s,401+v);
glVertex2f(492+s,401+v);
glVertex2f(477+s,383+v);
glVertex2f(475+s,385+v);
glEnd();
//right hand
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(510+s,399+v);
glVertex2f(510+s,397+v);
glVertex2f(477+s,383+v);
glVertex2f(475+s,385+v);
glEnd();
//bag
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(466+s,383+v);
glVertex2f(468+s,383+v);
glVertex2f(468+s,380+v);
glVertex2f(477+s,380+v);
glVertex2f(477+s,383+v);
glVertex2f(479+s,383+v);
glVertex2f(479+s,370+v);
glVertex2f(479+s,368+v);
glVertex2f(475+s,366+v);
glVertex2f(470+s,364+v);
glVertex2f(468+s,364+v);
glVertex2f(466+s,366+v);
glEnd();
//bag
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(466+s,383+v);
glVertex2f(468+s,383+v);
glVertex2f(468+s,380+v);
glVertex2f(477+s,380+v);
glVertex2f(477+s,383+v);
glVertex2f(479+s,383+v);
glVertex2f(479+s,370+v);
glVertex2f(479+s,368+v);
glVertex2f(475+s,366+v);
glVertex2f(470+s,364+v);
glVertex2f(468+s,364+v);
glVertex2f(466+s,366+v);
glEnd();
//girl3
for(l=0;l<=7;l++)
{
glColor3f(0.957,0.643,0.376);
draw_circle(55,462,l);
}
//eyes
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(57,461);
glEnd();
//hair
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(52,462);
glVertex2f(52,454);
glVertex2f(46,454);
glVertex2f(46,464);
glVertex2f(50,470);
glVertex2f(53,471);
glVertex2f(57,471);
glVertex2f(63,465);
glEnd();
//shirt
glColor3f(1.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(55,455);
glVertex2f(48,454);
glVertex2f(48,440);
glVertex2f(62,442);
glVertex2f(62,454);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(55,455);
glVertex2f(48,454);
glVertex2f(48,440);
glVertex2f(62,442);
glVertex2f(62,454);
glEnd();
//left leg
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(52,430);
glVertex2f(54,430);
glVertex2f(54,420);
glVertex2f(52,420);
glEnd();
//right leg
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(55,430);
glVertex2f(57,430);
glVertex2f(57,420);
glVertex2f(55,420);
glEnd();
//left leg
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(52,430);
glVertex2f(54,430);
glVertex2f(54,420);
glVertex2f(52,420);
glEnd();
//right leg
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(55,430);
glVertex2f(57,430);
glVertex2f(57,420);
glVertex2f(55,420);
glEnd();
//skirt
glColor3f(0.282,0.239,0.545);
glBegin(GL_POLYGON);
glVertex2f(48,440);
glVertex2f(62,442);
glVertex2f(66,430);
glVertex2f(44,430);
glEnd();
//skirt
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(48,440);
glVertex2f(62,442);
glVertex2f(66,430);
glVertex2f(44,430);
glEnd();
//right hand
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(55,454);
glVertex2f(55,452);
glVertex2f(69,447);
glVertex2f(69,449);
glEnd();
//left hand
glColor3f(0.957,0.643,0.376);
glBegin(GL_POLYGON);
glVertex2f(62,454);
glVertex2f(62,452);
glVertex2f(69,447);
glVertex2f(69,449);
glEnd();
//pond
glColor3f(c,e,f);
//glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(25,350);
glVertex2f(25,375);
glVertex2f(50,400);
glVertex2f(75,410);
glVertex2f(100,420);
glVertex2f(200,420);
glVertex2f(225,410);
glVertex2f(250,405);
glVertex2f(275,390);
glVertex2f(300,375);
glVertex2f(310,350);
glColor3f(0.690,0.878,0.902);
glVertex2f(300,320);
glVertex2f(275,300);
glVertex2f(250,295);
glVertex2f(225,290);
glVertex2f(200,285);
glVertex2f(175,280);
glVertex2f(150,280);
glVertex2f(125,280);
glVertex2f(100,290);
glVertex2f(75,300);
glVertex2f(50,310);
glEnd();
//pool cleaning
glColor3f(0.000,0.502,0.502);
glBegin(GL_POLYGON);
glVertex2f(66+o,446+n);
glVertex2f(68+o,448+n);
glVertex2f(148+o,350+n);
glVertex2f(146+o,348+n);
glEnd();
glColor3f(0.000,0.502,0.502);
glBegin(GL_POLYGON);
glVertex2f(142+o,344+n);
glVertex2f(150+o,336+n);
glVertex2f(158+o,344+n);
glVertex2f(152+o,354+n);
glVertex2f(143+o,344+n);
//glVertex2f()
glEnd();
//road boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();
//road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();
//waste in truck
glColor3f(0.545,0.271,0.075);
glBegin(GL_POLYGON);
glVertex2f(0+i,200);
glVertex2f(5+i,210);
glVertex2f(10+i,201);
glVertex2f(20+i,230);
glVertex2f(25+i,228);
glVertex2f(30+i,245);
glVertex2f(70+i,205);
glVertex2f(150+i,250);
glVertex2f(170+i,200);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(15+i,210);
glVertex2f(20+i,205);
glVertex2f(25+i,207);
glVertex2f(150+i,210);
glVertex2f(70+i,205);
glVertex2f(102+i,215);
glVertex2f(115+i,210);
glVertex2f(125+i,220);
glVertex2f(130+i,240);
glEnd();
//truck
glColor3f(0.000,0.392,0.000);
glBegin(GL_POLYGON);
glVertex2f(0+i,60);
glVertex2f(0+i,200);
glVertex2f(220+i,200);
glVertex2f(220+i,60);
glVertex2f(210+i,200);
glVertex2f(220+i,280);
glVertex2f(320+i,280);
glVertex2f(330+i,200);
glVertex2f(330+i,60);
glVertex2f(220+i,60);
glEnd();
//line
glColor3f(0.235,0.702,0.443);
glBegin(GL_POLYGON);
glVertex2f(0+i,180);
glVertex2f(330+i,180);
glVertex2f(330+i,160);
glVertex2f(0+i,160);
glEnd();
//window
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(215+i,270);
glVertex2f(300+i,270);
glVertex2f(310+i,210);
glVertex2f(215+i,210);
glEnd();
glColor3f(0.251,0.878,0.816);
glBegin(GL_POLYGON);
glVertex2f(218+i,265);
glVertex2f(285+i,265);
glColor3f(0.686,0.933,0.933);
glVertex2f(295+i,215);
glVertex2f(218+i,215);
glEnd();
//wheels
for(l=0;l<=35;l++)
{
glColor3f(0.0,0.0,0.0);
draw_circle(50+i,60,l);
draw_circle(270+i,60,l);
}
//dustbin1
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(950,370);
glVertex2f(1000,370);
glVertex2f(995,320);
glVertex2f(955,320);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(960,365);
glVertex2f(990,365);
glVertex2f(985,355);
glVertex2f(965,355);
glEnd();
glColor3f(0.0,0.0,0.0);
glRasterPos2f(949,345);
declare("DUSTBIN");
}
//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(350,325);
glVertex2f(350,395);
glVertex2f(365,395);
glVertex2f(365,325);
glEnd();
for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(340,400,l);
		draw_circle(380,400,l);
	if(l<=25)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(350,440,l);
		draw_circle(370,440,l);
	}
	if(l<=20)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(360,465,l);
	}
	}
	//tree2
	glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(1050,325);
glVertex2f(1050,395);
glVertex2f(1065,395);
glVertex2f(1065,325);
glEnd();
for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1040,400,l);
		draw_circle(1080,400,l);
	  if(l<=25)
      {
		glColor3f(0.0,0.5,0.0);
		draw_circle(1050,440,l);
		draw_circle(1070,440,l);
	  }
      if(l<=20)
	  {
		glColor3f(0.0,0.5,0.0);
		draw_circle(1060,465,l);
	  }
	}
	//tree3
	glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(850,350);
glVertex2f(850,375);
glVertex2f(865,375);
glVertex2f(865,350);
glEnd();
for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(840,400,l);
		draw_circle(880,400,l);
	  if(l<=25)
      {
		glColor3f(0.0,0.5,0.0);
		draw_circle(850,440,l);
		draw_circle(870,440,l);
	  }
    if(l<=20)
	  {
		glColor3f(0.0,0.5,0.0);
		draw_circle(860,465,l);
	  }
	}
//house2
glColor3f(1.000,0.843,0.000);
glBegin(GL_POLYGON);
glVertex2f(600,375);
glVertex2f(600,450);
glVertex2f(650,525);
glColor3f(1.000,1.000,0.000);
glVertex2f(700,450);
glVertex2f(700,368);
glEnd();
//door
glColor3f(0.5,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(640,375);
glVertex2f(640,410);
glVertex2f(660,410);
glVertex2f(660,375);
glEnd();
//roof
glColor3f(0.545,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(700,450);
glVertex2f(650,525);
glVertex2f(750,525);
glVertex2f(800,450);
glEnd();
//
glColor3f(1.000,0.843,0.000);
glBegin(GL_POLYGON);
glVertex2f(700,368);
glVertex2f(700,450);
glColor3f(1.000,1.000,0.000);
glVertex2f(780,450);
glVertex2f(780,375);
glEnd();
//window
glColor3f(0.251,0.878,0.816);
glBegin(GL_POLYGON);
glVertex2f(725,400);
glVertex2f(725,420);
glColor3f(0.686,0.933,0.933);
glVertex2f(740,420);
glVertex2f(740,400);
glEnd();
glFlush();

}
void idle()
{
    a+=1;
    ++m;
    o+=1.0;
    n+=1.0;
    p-=1.0;
    q-=1.0;
    s+=0.75;
    v-=0.75;
    c-=0.002;
    e+=0.004;
    f+=0.006;
    if(c<0.0)
    {
    c=0;}
    if(e>0.9)
    {
    e=0.9;
    }
    if(f>0.9)
    {
    f=0.9;
    }
    if(a>2)
    {
    a=0.0;
    }
if(o>2)
{ o=n=p=q=0.0;
}
if(i>480 && z!=250)
{
z++;
i=i;
}
else
{
 i+=speed/10;
}
if(m>1100)
	 m=0.0;
glutPostRedisplay();

}
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
exit(0);
}
void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'd':
	case 'D':
		dirt=1;
		break;

	case 'c':
case 'C':
	dirt=0;
	i=0;
    z=0;
	s=0.0;
	v=0.0;
	c=0.627,e=0.322 ,f=0.176 ;
		break;
   };
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
if(t<50)
	{
		for(t=0;t<=300;t++)
		{
			title1();
			glutPostRedisplay();
			glutSwapBuffers();
			glFlush();
		}
	}
	else
draw_object();
title();
glFlush();
}
int main(int argc,char** argv)
{
	printf("Press 'd' or 'D' for dirt view \n");
	printf("Press 'c' or 'C' for clean view \n");
	//printf("Press RIGHT MOUSE BUTTON to display menu  \n");
	printf("Press LEFT MOUSE BUTTON to quit the program \n");
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
    glutCreateWindow("Swachh Bharath");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
	return 0;
}



