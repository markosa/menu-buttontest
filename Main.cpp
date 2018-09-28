/*
 * Main.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: markos
 */

#include <stdio.h>

#include "Configuration.h"
#include "Settings.h"
#include "Button.h"
#include "Menu.h"
#include "MenuNode.h"

void setupMenu();
void init();

static Button BUTTON_PRGSET(0, 100, "PRGSET");
static Button BUTTON_SET(101, 200, "SET");
static Button BUTTON_STA(201, 300, "STA");
static Button BUTTON_RUN(301, 400, "RUN");
static Button BUTTON_ALARM(401, 500, "ALARM");
static Settings settings = Settings();
static Menu menu = Menu();
void callBack(int value) {
	debug_print("Callback: %d  \n", value);
}

static MenuNode MAIN_PRGSET = MenuNode("PRGSET MENU",&BUTTON_PRGSET, &callBack);
static MenuNode PRGSET_DEV = MenuNode("PRGSET DEV",&BUTTON_PRGSET, &callBack);
static MenuNode PRGSET_STOP = MenuNode("PRGSET STOP",&BUTTON_PRGSET, &callBack);
static MenuNode PRGSET_FIX = MenuNode("PRGSET FIX",&BUTTON_PRGSET, &callBack);


static MenuNode MAIN_SET = MenuNode("SET MENU",&BUTTON_SET, &callBack);
static MenuNode SET_SPEED = MenuNode("SET SPEED",&BUTTON_SET, &callBack);
static MenuNode SET_TRANSITION = MenuNode("SET TRANS",&BUTTON_SET, &callBack);

static MenuNode MAIN_STA = MenuNode("STA MENU",&BUTTON_STA, &callBack);
static MenuNode STA_STOP = MenuNode("STA STOP",&BUTTON_STA, &callBack);

static MenuNode MAIN_RUN = MenuNode("RUN MENU",&BUTTON_RUN, &callBack);
static MenuNode RUN_CONFIRM_DEV_START = MenuNode("RUN DEV CONFIRM",&BUTTON_RUN, &callBack);
static MenuNode RUN_STOP = MenuNode("RUN STOP",&BUTTON_RUN, &callBack);
static MenuNode RUN_FIX = MenuNode("RUN FIX",&BUTTON_RUN, &callBack);
static MenuNode RUN_WASH = MenuNode("RUN WASH",&BUTTON_RUN, &callBack);

static MenuNode MAIN_ALARM = MenuNode("ALARM MENU",&BUTTON_ALARM, &callBack);

static MenuNode* PRGSET_SUB[]={&PRGSET_DEV,&PRGSET_STOP,&PRGSET_FIX};
static MenuNode* SET_SUB[]={&SET_SPEED,&SET_TRANSITION};
static MenuNode* STA_SUB[]={&STA_STOP};
static MenuNode* RUN_SUB[]={&RUN_CONFIRM_DEV_START,&RUN_STOP,&RUN_FIX,&RUN_WASH};



void init() {
	setupMenu();
	settings.load();
}

void setupMenu() {
	menu.add(&MAIN_PRGSET,PRGSET_SUB, (sizeof(PRGSET_SUB) / sizeof(PRGSET_SUB[0])));
	menu.add(&MAIN_SET,SET_SUB, (sizeof(SET_SUB) / sizeof(SET_SUB[0])));
	menu.add(&MAIN_STA,STA_SUB, (sizeof(STA_SUB) / sizeof(STA_SUB[0])));
	menu.add(&MAIN_RUN,RUN_SUB, (sizeof(RUN_SUB) / sizeof(RUN_SUB[0])));
	menu.add(&MAIN_ALARM,NULL, 0);
}

int main(void) {

	init();


	while (1) {
		char c;
		printf("\nq=PRGSET w=SET e=STA r=RUN t=ALARM\n");

		c = getchar();getchar();
		printf("Pressed: %c\n", c);
		Button* buttonPressed = NULL;
		switch (c) {
		case 'q':
			printf("\nPRGSET****\n");
			buttonPressed = &BUTTON_PRGSET;
			break;
		case 'w':
			printf("\SET****\n");
			buttonPressed = &BUTTON_SET;

			break;
		case 'e':
			printf("\STA****\n");
			buttonPressed = &BUTTON_STA;

			break;
		case 'r':
			printf("\RUN****\n");
			buttonPressed = &BUTTON_RUN;

			break;
		case 't':
			printf("\ALARM****\n");
			buttonPressed = &BUTTON_ALARM;

			break;

		}
		if (buttonPressed == NULL) {
			printf("null\n");
		}


		menu.move(buttonPressed, 100);
		MenuNode* current = menu.getCurrentNode();

	}

	return 0;
}

