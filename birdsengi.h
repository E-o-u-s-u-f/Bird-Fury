#include "iGraphics.h"
char sengi[28][30] = { "image/sengi/sengi001.png", "image/sengi/sengi002.png", "image/sengi/sengi003.png", "image/sengi/sengi004.png", "image/sengi/sengi005.png", "image/sengi/sengi006.png", "image/sengi/sengi007.png", "image/sengi/sengi008.png", "image/sengi/sengi009.png", "image/sengi/sengi010.png", "image/sengi/sengi011.png", "image/sengi/sengi012.png", "image/sengi/sengi013.png", "image/sengi/sengi014.png", "image/sengi/sengir001.png", "image/sengi/sengir002.png", "image/sengi/sengir003.png", "image/sengi/sengir004.png", "image/sengi/sengir005.png", "image/sengi/sengir006.png", "image/sengi/sengir007.png", "image/sengi/sengir008.png", "image/sengi/sengir009.png", "image/sengi/sengir010.png", "image/sengi/sengir011.png", "image/sengi/sengir012.png", "image/sengi/sengir013.png", "image/sengi/sengir014.png" };
int x = 0, y = 340; int index = 0;

struct sengis{
	char image[40];
	int x, y;
	bool isShow = false;
}sengis[20];

void initiateEnemy(){

	for (int i = 0; i < 20; i++){

		strcpy(sengis[i].image, sengi[i % 7]);
		sengis[i].x = 100;
		sengis[i].y = 850;
		sengis[i].isShow = false;
	}
}

void addNewEnemyCar(){

	for (int i = 0; i < 20; i++){

		if (sengis[i].isShow == false){

			sengis[i].isShow = true;
			sengis[i].x = rand() % (1029 - 212) + 212;
			sengis[i].y = 850;
			break;
		}
	}
}

void changesengi(){

	for (int i = 0; i < 20; i++){

		if (sengis[i].isShow == true){
			iShowImage(sengis[i].x, sengis[i].y, 65, 65, iLoadImage(sengis[i].image));
		}
	}
}

