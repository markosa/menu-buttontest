/*
 * Main.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: markos
 */

#include <stdio.h>

#include "MenuNode.h"
#include "Menu.h"
#include "Configuration.h"
#include "Settings.h"

void setupMenu();
void init();

static Menu menu = Menu();
static Button BUTTON_PRGSET = Button(0, 100, "PRGSET");
static Button BUTTON_SET = Button(101, 200, "SET");
static Button BUTTON_STA = Button(201, 300, "STA");
static Button BUTTON_RUN = Button(301, 400, "RUN");
static Button BUTTON_ALARM = Button(401, 500, "ALARM");
static Settings settings = Settings();

static MenuNode PRGSET_DEV = MenuNode("PRGSET_DEV", &BUTTON_PRGSET);
static MenuNode PRGSET_STOP = MenuNode("PRGSET_STOP", &BUTTON_PRGSET);
static MenuNode PRGSET_FIX = MenuNode("PRGSET_FIX", &BUTTON_PRGSET);
static MenuNode SET_SPEED = MenuNode("SET", &BUTTON_SET);
static MenuNode SET_TRANSITION = MenuNode("SET", &BUTTON_SET);
static MenuNode STA = MenuNode("STA", &BUTTON_STA);
static MenuNode RUN = MenuNode("RUN", &BUTTON_RUN);
static MenuNode ALARM = MenuNode("ALARM", &BUTTON_ALARM);

void init() {
	setupMenu();
	settings.load();
}

void setupMenu() {

	// PRGSET

	PRGSET_DEV.addRightNode(&PRGSET_STOP);
	PRGSET_DEV.addRightNode(&PRGSET_FIX);
	SET_SPEED.addRightNode(&SET_TRANSITION);

	menu.addMenuNode(&PRGSET_DEV);
	menu.addMenuNode(&SET_SPEED);
	menu.addMenuNode(&STA);
	menu.addMenuNode(&RUN);
	menu.addMenuNode(&ALARM);

}

int main(void) {

	init();

	return 0;
}

