/*
 * Main.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: markos
 */

#include <stdio.h>

#include "MenuNode.h"
#include "Menu.h"

Menu menu = Menu();

void setupMenu();
void setupButtons();

Button BUTTON_PRGSET = Button(0,100,"PRGSET");
Button BUTTON_SET = Button(101,200,"SET");
Button BUTTON_STA = Button(201,300,"STA");
Button BUTTON_RUN = Button(301,400,"RUN");
Button BUTTON_ALARM = Button(401,500,"ALARM");

void setupButons() {

}

void setupMenu() {

	// PRGSET
	MenuNode PRGSET_DEV = MenuNode("PRGSET_DEV", &BUTTON_PRGSET);
	MenuNode PRGSET_STOP = MenuNode("PRGSET_STOP",&BUTTON_PRGSET);
	MenuNode PRGSET_FIX = MenuNode("PRGSET_FIX",&BUTTON_PRGSET);
	PRGSET_DEV.addRightNode(&PRGSET_STOP);
	PRGSET_DEV.addRightNode(&PRGSET_FIX);

	MenuNode SET_SPEED = MenuNode("SET", &BUTTON_SET);
	MenuNode SET_TRANSITION = MenuNode("SET", &BUTTON_SET);
	SET_SPEED.addRightNode(&SET_TRANSITION);

	MenuNode STA = MenuNode("STA", &BUTTON_STA);
	MenuNode RUN = MenuNode("RUN", &BUTTON_RUN);
	MenuNode ALARM = MenuNode("ALARM", &BUTTON_ALARM);

	menu.addMenuNode(&PRGSET_DEV);
	menu.addMenuNode(&SET_SPEED);
	menu.addMenuNode(&STA);
	menu.addMenuNode(&RUN);
	menu.addMenuNode(&ALARM);

}

int main(void) {

	MenuNode root = MenuNode("testName");

	MenuNode left2 = MenuNode("L2");
	MenuNode left3 = MenuNode("L3");

	MenuNode right1 = MenuNode("R1");
	MenuNode right2 = MenuNode("R2");
	MenuNode right3 = MenuNode("R3");

	/*

	 root.addLeftNode(&left1);
	 root.addLeftNode(&left2);
	 root.addLeftNode(&left3);
	 root.addRightNode(&right1);
	 root.addRightNode(&right2);
	 root.addRightNode(&right3);


	 MenuNode* L1 = root.getLeftNode();

	 if (L1 == NULL) {
	 printf("L1 null");
	 }

	 //printf("L1->getName(): %s" , L1->getName());

	 /*
	 *
	 * Menu menu = Menu();
	 * menu.addNode(setprg);
	 * menu.addNode(set);
	 * menu.addNode(start);
	 * menu.addNode(run);
	 *
	 * Buttons  b = menu.getAvailableButtonsInCurrentView();
	 *
	 *
	 *
	 */

	Menu menu = Menu();
	menu.addMenuNode(&right1);
	menu.addMenuNode(&right2);
	menu.addMenuNode(&right3);

	return 0;
}

