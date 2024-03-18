#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string.h>
using namespace std;


#include "iGraphics.h"
#include "bitmap_loader.h"
#define birdGap 15;
#define birdHeight 65;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

int bc = rand() % 3;
char a=200, b=100, c;
int x = 0,y = 340;
int px=100,py=400 ;
int rx = 60, ry = 300;
int music = 1;
bool musicOn = true;
int cmx = 0, cmy = 0;
int bikbird = 0;
int index = 0;
int score = 0, life = 5;
char gain[2000];
int indexphoenix = 0,indexraven=0;
int bullet = 6;
int shotfire = 0;
char phoenix[6][30] = { "image/phoenix/phoenix001.png", "image/phoenix/phoenix002.png", "image/phoenix/phoenix003.png", "image/phoenix/phoenixr001.png", "image/phoenix/phoenixr002.png", "image/phoenix/phoenixr003.png" };
char raven_fall[5][40] = { "image/raven_fall/ravenfall001.png", "image/raven_fall/ravenfall002.png", "image/raven_fall/ravenfall003.png", "image/raven_fall/ravenfall004.png", "image/raven_fall/ravenfall005.png" };
char raven[10][30] = { "image/ravens/1.png", "image/ravens/2.png", "image/ravens/3.png", "image/ravens/4.png", "image/ravens/5.png", "image/ravens/6.png", "image/ravens/7.png", "image/ravens/8.png", "image/ravens/9.png", "image/ravens/10.png" };
char raven_fly[10][40] = { "image/raven_fly/1.png","image/raven_fly/2.png","image/raven_fly/3.png","image/raven_fly/4.png","image/raven_fly/5.png","image/raven_fly/6.png","image/raven_fly/7.png","image/raven_fly/8.png","image/raven_fly/9.png","image/raven_fly/10.png" };
char heart[5][30] = { "image/life.png", "image/life.png", "image/life.png", "image/life.png", "image/life.png" };
char bulleti[6][30] = { "image/bullet2.png", "image/bullet2.png", "image/bullet2.png", "image/bullet2.png", "image/bullet2.png", "image/bullet2.png" };
char sengi[28][30] = { "image/sengi/sengi001.png", "image/sengi/sengi002.png", "image/sengi/sengi003.png", "image/sengi/sengi004.png", "image/sengi/sengi005.png", "image/sengi/sengi006.png", "image/sengi/sengi007.png", "image/sengi/sengi008.png", "image/sengi/sengi009.png", "image/sengi/sengi010.png", "image/sengi/sengi011.png", "image/sengi/sengi012.png", "image/sengi/sengi013.png", "image/sengi/sengi014.png", "image/sengi/sengir001.png", "image/sengi/sengir002.png", "image/sengi/sengir003.png", "image/sengi/sengir004.png", "image/sengi/sengir005.png", "image/sengi/sengir006.png", "image/sengi/sengir007.png", "image/sengi/sengir008.png", "image/sengi/sengir009.png", "image/sengi/sengir010.png", "image/sengi/sengir011.png", "image/sengi/sengir012.png", "image/sengi/sengir013.png", "image/sengi/sengir014.png" };
boolean sengic = false, phoenixc = false, ravenc = false;
int n=3,i;
void birdcome();
void phoenixcome();
void sengicome();
void ravencome();
void fixedtheplace();
void shot(int cmx, int cmy);

void drawLandingPage();
void drawHomePage();
void drawNewGamePage();
void drawScorePage();
void drawStoryPage();
void drawInstructionPage();
void drawEndGamePage();
void drawMidGamePage();
void drawHardGamePage();
void drawLevelPage();

void homePageHandler();
void newGamePageHandler();
void scorePageHandler();
void storyPageHandler();
void instructionPageHandler();
void backButtonHandler();
void endGamePageHandler();
void midGamePageHandler();
void hardGamePageHandler();
void levelPageHandler();

int homePagehandle = 0;
int newGamePageHandle = 0;
int scorePageHandle = 0;
int storyPageHandle = 0;
int instructionPageHandle = 0;
int endGamePageHandle = 0;
int midGamePageHandle = 0;
int hardGamePageHandle = 0;
int levelPageHandle = 0;


int landingPage = 1;
int homePage = 0;
int newGamePage = 0;
int scorePage = 0;
int storyPage = 0;
int instructionPage = 0;
int endGamePage = 0;
int midGamePage = 0;
int hardGamePage = 0;
int levelPage = 0;
//typedef struct highScore highScore;

void lifeClose(){
	endGamePage = 1;
}


void newHighScore();
void readScore();
int len = 0;
char str1[30];
boolean newscore = true;




struct highScore{
	int score;
	char name[20] ;
};
typedef struct highScore Player;
void sortScore(Player r[], Player n){
	
	int i = 0;
	while (i<5 && n.score <= r[i].score)
	{
		i++;
	}
	if (i<5)
	{
		for (int j = 4; j>i; j--)
		{
			Player t = r[j];
			r[j] = r[j - 1];

		}
		r[i] = n;
	}
}
Player highScore[3];

void newHighScore()
{
	FILE *fp = fopen("HighScore.txt", "r");
	if (fp == NULL){
		printf("something went wrong");
	}
	else{

		for (int i = 0; i < 3; i++)
		{
			fscanf(fp, "%d\n",&highScore[i].score);
		}
		fclose(fp);
		FILE *fp = fopen("HighScore.txt", "w");
		int i;
		char n[30];

		//if (newscore)
		//{
			for (  i = 0; i < 3; i++)
			{
				if (highScore[i].score < score)
				{
					
					//highScore[2].score = score;
					//strcpy(Player[2].name, str1);
					/*for (int i = 0; i < 3; i++){
						for (int j = 3; j >i; j--){
							if (highScore[j].score< highScore[j-1].score){

								int t = highScore[j - 1].score;
								highScore[j - 1].score = highScore[j].score;
								highScore[j].score = t;*/

								/*char n[20];
								strcpy(n, Player[j - 1].name);
								strcpy(Player[j - 1].name, Player[j].name);
								strcpy(Player[j].name, n);
								*/
					for (int j = i; j <3; j++)
					{
						highScore[j + 1].score = highScore[j].score;

					}
					break;

				}
						
			}
			highScore[i].score = score;
			score = 0;
			bullet = 6;
			life = 5;
					}
				
					for (int k = 0; k < 3; k++)
					{
                         fprintf(fp, "%d\n", highScore[k].score);
					}
						
					fclose(fp);

					//newscore = false;
					


				}
	


//}
void readScore()
{
	newHighScore();
	FILE *fp = fopen("HighScore.txt", "r");
	//highScore p;
	if (fp == NULL){
		printf("something went wrong");
		exit(0);
	}
	else{

		char showName[3][10], showScore[3][5];

		for (int k = 0; k < 3; k++)
		{
			fscanf(fp, "%d\n", &highScore[k].score);
		}
		for (int k = 0; k < 3; k++){
			//sprintf(showName[k], "%s", Player[k].name);
			sprintf(showScore[k], "%d", highScore[k].score);
			iSetColor(0, 0, 0);
			//iText(310, 275 - 40 * k, showName[k], GLUT_BITMAP_9_BY_15);
			iText(320, 265 - 70 * k, showScore[k], GLUT_BITMAP_TIMES_ROMAN_24);

		}
		fclose(fp);
	}
}
	
/*
void showChar()
{
	iSetColor(255, 255, 255);
	iText(400, 500, "ENTER YOUR NAME:", GLUT_BITMAP_HELVETICA_10);
	iRectangle(495, 450, 160, 30);
	iText(500, 460, str1, GLUT_BITMAP_HELVETICA_10);

}
void takeinput(unsigned key)
{
	if (key == '\r')
	{
		homePage = 1;
		newHighScore();

	}
	else if (key == '\b')
	{
		if (len <= 0)
		{
			len = 0;

		}
		else
			len--;
			
		str1[len] = '\0';
		
		
	}
}*/
/*void writeScore()
{
	
}*/
void shotSound(bool x){
	if (x == 1)
	{
		PlaySound("fireshot.wav", NULL, SND_ASYNC);
		x = 0;
	}
}


void iDraw()
{
	iClear();
	
	if (landingPage == 1)
	{
		drawLandingPage();
	}
	else if (homePage == 1)
	{
		drawHomePage();
	}
	else if (newGamePage == 1)
	{
		drawNewGamePage();
	}
	else if (scorePage == 1)
	{
		drawScorePage();
	}
	else if (storyPage == 1)
	{
		drawStoryPage();
	}
	else if (instructionPage == 1)
	{
		drawInstructionPage();
	}
	else if (levelPage == 1){
		drawLevelPage();
	}
	else if (midGamePage == 1){
		drawMidGamePage();
	}
	else if (hardGamePage == 1){
		drawHardGamePage();
	}
	else if ( endGamePage==1){
		drawEndGamePage();
		//showChar();
	}
	
	
	/*
	iShowImage(0, 0,740,470,iLoadImage("image/summer.png" ));
	iShowImage(cmx, cmy, 50, 50, iLoadImage("image/aim.png"));
	    birdcome();
	
		sengicome();
	
		phoenixcome();
	*/
	/*else if (ravenc)
	{
		ravencome();
	}
	*/
}


/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
	cmx = mx;
	cmy = my;
	
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//printf("%d %d ", mx, my);
		if (landingPage == 1 && (mx >= 190 && mx <= 545) && (my >= 125 && my <= 345))
		{
			homePageHandler();
		}
		else if (homePage == 1 && (mx >= 305 && mx <= 432) && (my >= 242 && my <= 280))
		{
			levelPageHandler();
		}
		else if (levelPage == 1 && (mx >= 298 && mx <= 440) && (my >= 273 && my <= 310))
		{
			newGamePageHandler();
			shotSound(GLUT_LEFT_BUTTON);
		}
		else if (levelPage == 1 && (mx >= 299 && mx <= 440) && (my >= 212 && my <= 252))
		{
			midGamePageHandler();
			shotfire = 1;
			shotSound(GLUT_LEFT_BUTTON);
		}
		else if (levelPage == 1 && (mx >= 299 && mx <= 440) && (my >= 150 && my <= 192))
		{
			hardGamePageHandler();
			shotfire = 1;
		}
		else if (homePage == 1 && (mx >= 305 && mx <= 432) && (my >= 183 && my <= 223))
		{
			scorePageHandler();
		}
		else if (homePage == 1 && (mx >= 305 && mx <= 432) && (my >= 125 && my <= 164))
		{
			storyPageHandler();
		}
		else if (homePage == 1 && (mx >= 305 && mx <= 432) && (my >= 68 && my <= 106))
		{
			instructionPageHandler();
		}
		else if (( storyPage == 1 || instructionPage == 1) && (mx >= 0 && mx <= 50) && (my >= 420 && my <= 470))
		{
			backButtonHandler();
		}
		else if (scorePage == 1 && (mx >= 495 && mx <= 540) && (my >= 369 && my <= 410)){
			backButtonHandler();
		}
		else if (endGamePage == 1 && ((mx >= 234 && mx <= 295) && (my >= 62 && my <= 84)))
		{
			levelPageHandler();
		}
		else if (endGamePage == 1 && (mx >= 467 && mx <= 517) && (my >= 63 && my <= 86)){
			backButtonHandler();
		}
		else if (newGamePage == 1||midGamePage==1||hardGamePage==1){
			bullet--;
		}
		

		cmx = mx;
		cmy = my;
		shot(cmx, cmy);
		/*if (((cmx <= rx + 35 && cmx >= rx - 35) && (cmy <= ry + 35 && cmy >= ry - 35))){
			endGamePageHandler();
	}*/
		
		
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		bullet = 6;
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	/*if (endGamePage == 1)
	{
		takeinput(key);
	}*/
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT)
	{
		
		
	}
	else if (key == GLUT_KEY_LEFT)
	{
		

	}
	
	else if (key == GLUT_KEY_HOME)
	{
		
	}
	else if (key == GLUT_KEY_F1){
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("gameplaymusic.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
}

void changesengil()
{
	x += 10;
    index++;

	if (index == 13)
	{
		index = 0;

	}
	if (x == 740 )
	{
		life--;
		y = rand() % 450;
		if (y<151 || y == py || y == ry){
			y = rand() % 450;
		}
		x = 0;
	}
	

}
void changesengir()
{
	x += 10;
	index++;

	if (index == 13)
	{
		index = 0;


	}
	if (x == 740)
	{
		y = rand() % 450;
		if (y<151 || y == py || y == ry){
			y = rand() % 450;
		}
		x = 0;
	}


}
void changephoenixl( )
{
	
	px += 10;
	indexphoenix++;

	if (indexphoenix == 3)
	{
		indexphoenix = 0;

	}

	if (px == 740)
	{
		py = rand() % 450;
		if (py<151 || py == y || py == ry)
		{
			py = rand() % 450;
		}
		px =0;
	}


}

void changeravenl()
{
	
	rx += 10;
	indexraven++;

	if (indexraven == 10)
	{
		indexraven = 0;

	}
	if (rx == 740)
	{
		ry = rand() % 450;
		if (ry<151 || ry == py || ry == y)
		{
			ry = rand() % 450;
		}
		rx = 0;
	}


}
/*void birdcome()
{

	int y = rand() % 6;
	if ( y == 0)
	{
		sengicome();
	}
	else if (y == 1)
	{
		phoenixcome();

	}
	else if (y == 2)
	{
		ravencome();
	}
}
*/
 void sengicome()
{
iShowImage(x, y, 65, 65, iLoadImage(sengi[index]));
}
void ravencome()
{
iShowImage(rx, ry, 130, 130, iLoadImage(raven[indexraven]));
}
void phoenixcome()
{
	iShowImage(px, py, 65, 65, iLoadImage(phoenix[indexphoenix]));
}


void drawLandingPage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/12 (1).png"));
}
void drawHomePage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/menu final.png"));
}
void drawLevelPage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/LEVEL.png"));

}
void drawNewGamePage()
{
	iShowImage(0, 0, 740, 470, iLoadImage("image/summer.png"));
	iShowImage(cmx, cmy, 70, 70, iLoadImage("image/aim.png"));
	sengicome();
	phoenixcome();
	ravencome();
	sprintf_s(gain, "SCORE:%d", score);
	iSetColor(0, 0, 0);
	iText(600, 440, gain, GLUT_BITMAP_TIMES_ROMAN_24);
	for (int i = 0; i < bullet; i++){
		iShowImage(i * 30, 2, 45, 35, iLoadImage(bulleti[i]));
	}
	for (int i = 0; i < life; i++){
		iShowImage((700-(i * 30)), 2, 45, 35, iLoadImage(heart[i]));
	}
	

}
void drawMidGamePage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/mid.png"));
	iShowImage(cmx, cmy, 70, 70, iLoadImage("image/aim.png"));
	sengicome();
	phoenixcome();
	ravencome();
	sprintf_s(gain, "SCORE:%d", score);
	iSetColor(0, 0, 0);
	iText(600, 440, gain, GLUT_BITMAP_TIMES_ROMAN_24);
	for (int i = 0; i < bullet; i++){
		iShowImage(i * 30, 2, 45, 35, iLoadImage(bulleti[i]));
	}
	for (int i = 0; i < life; i++){
		iShowImage((700 - (i * 30)), 2, 45, 35, iLoadImage(heart[i]));
	}

}
void drawHardGamePage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/hard.png"));
	iShowImage(cmx, cmy, 70, 70, iLoadImage("image/aim.png"));
	sengicome();
	phoenixcome();
	ravencome();
	sprintf_s(gain, "SCORE:%d", score);
	iSetColor(0, 0, 0);
	iText(600, 440, gain, GLUT_BITMAP_TIMES_ROMAN_24);
	for (int i = 0; i < bullet; i++){
		iShowImage(i * 30, 2, 45, 35, iLoadImage(bulleti[i]));
	}
	for (int i = 0; i < life; i++){
		iShowImage((700 - (i * 30)), 2, 45, 35, iLoadImage(heart[i]));
	}

}
void drawScorePage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/Score_card.png"));
	readScore();
	endGamePage = 1;


}
void drawStoryPage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/story.png"));
	iShowImage(0, 420, 50, 50, iLoadImage("image/backbutton.png"));
}
void drawInstructionPage(){
	iShowImage(0, 0, 740, 470, iLoadImage("image/instruction.png"));
	iShowImage(0, 420, 50, 50, iLoadImage("image/backbutton.png"));
}
void drawEndGamePage(){

	iShowImage(0, 0, 740, 470, iLoadImage("image/end.png"));
	
	iSetColor(0, 0, 0);
	iText(320, 175, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf_s(gain, "%d", score);
	iText(410, 175, gain, GLUT_BITMAP_TIMES_ROMAN_24);
}


void homePageHandler()
{
	landingPage = 0;
	homePage = 1;
}
void levelPageHandler()
{
	landingPage = 0;
	homePage = 0;
	scorePage = 0;
	storyPage = 0;
	instructionPage = 0;
	newGamePage = 0;
	midGamePage = 0;
	hardGamePage = 0;
	levelPage = 1;
}
void newGamePageHandler()
{
	
	landingPage = 0;
	homePage = 0;
	levelPage = 0;
	midGamePage = 0;
	hardGamePage = 0;
	newGamePage = 1;
	score = 0;
	bullet = 6;
}
void midGamePageHandler(){
	landingPage = 0;
	homePage = 0;
	newGamePage = 0;
	hardGamePage = 0;
	levelPage = 0;
	midGamePage = 1;
	score = 0;
	bullet = 6;
}
void hardGamePageHandler(){
	landingPage = 0;
	homePage = 0;
	newGamePage = 0;
	midGamePage = 0;
	levelPage = 0;
	hardGamePage = 1;
	score = 0;
	bullet = 6;
}
void scorePageHandler()
{
	landingPage = 0;
	homePage = 0;
	newGamePage = 0;
	scorePage = 1;
}
void storyPageHandler()
{
	landingPage = 0;
	homePage = 0;
	newGamePage = 0;
	scorePage = 0;
	storyPage = 1;
}
void instructionPageHandler()
{
	landingPage = 0;
	homePage = 0;
	newGamePage = 0;
	scorePage = 0;
	storyPage = 0;
	instructionPage = 1;
}

void backButtonHandler()
{
	scorePage = 0;
	storyPage = 0;
	newGamePage = 0;
	midGamePage = 0;
	hardGamePage = 0;
	levelPage = 0;
	instructionPage = 0;
	homePage = 1;
}
void endGamePageHandler(){

	newGamePage = 0;
	midGamePage = 0;
	hardGamePage = 0;
	endGamePage = 1;
	

}
void shot(int cmx, int cmy){

	//PlaySound("fireshot.wav", NULL, SND_ASYNC);

	if ((cmx <= x + 25 && cmx >= x - 25) && (cmy <= y + 25 && cmy >= y - 25) && bullet>0)
	{
		score = score + 5;
		y = rand() % 450;
		if (y<151 || y == py || y == ry){
			y = rand() % 450;
		}
		x = 0;

	}
	else if ((cmx <= px + 25 && cmx >= px - 25) && (cmy <= py + 25 && cmy >= py - 25) && bullet>0)
	{
		score = score + 10;
		if (life < 5){
			life++;
		}
		py = rand() % 450;
		if (py<151 || py == y || py == ry)
		{
			py = rand() % 450;
		}
		px = 0;
	}
	else if ((((cmx <= rx + 30 && cmx >= rx - 30) && (cmy <= ry + 30 && cmy >= ry - 30))||life ==0) && bullet>0)
	{
		newGamePage = 0;
		midGamePage = 0;
		hardGamePage = 0;
		endGamePage = 1;
		//iShowImage(0, 0, 740, 470, iLoadImage("image/end.png"));
		
	}
	
}





int main()
{
	
	///srand((unsigned)time(NULL));
	iSetTimer(60, changesengil);
	iSetTimer(40, changephoenixl);
	iSetTimer(40, changeravenl);
	/*iSetTimer(60, sengicome);
	iSetTimer(40, phoenixcome);
	iSetTimer(40, ravencome);*/
	if(musicOn){
		PlaySound("gameplaymusic.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	
	iInitialize(740,470,"Bird-Fury");
	///updated see the documentations
	
	iStart();
	return 0;
}