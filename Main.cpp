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
static Button BUTTON_PRGSET(0, 100, "PRGSET");
static Button BUTTON_SET(101, 200, "SET");
static Button BUTTON_STA(201, 300, "STA");
static Button BUTTON_RUN(301, 400, "RUN");
static Button BUTTON_ALARM(401, 500, "ALARM");
static Settings settings = Settings();

static MenuNode PRGSET_DEV("PRGSET_DEV", &BUTTON_PRGSET);
static MenuNode PRGSET_STOP("PRGSET_STOP", &BUTTON_PRGSET);
static MenuNode PRGSET_FIX("PRGSET_FIX", &BUTTON_PRGSET);
static MenuNode SET_SPEED("SET_SPEED", &BUTTON_SET);
static MenuNode SET_TRANSITION("SET_TRANSITION", &BUTTON_SET);
static MenuNode STA("STA", &BUTTON_STA);
static MenuNode RUN("RUN", &BUTTON_RUN);
static MenuNode ALARM("ALARM", &BUTTON_ALARM);

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

