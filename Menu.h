/*
 * Menu.h
 *
 *  Created on: Sep 22, 2018
 *      Author: markos
 */

#ifndef MENU_H_
#define MENU_H_

#include "Configuration.h"
#include "MenuNode.h"
#include "Button.h"
class Menu {

public:
	Menu();
	void addMenuNode(MenuNode *node);
	bool isMainMenu();
	void buttonPressed(char *buttonName, int value);
	void reset();


private:
	MenuNode* nodes[MENU_MAX_NODES];
	int nodeCount;
	MenuNode* currentNode;
	void Menu::buttonPressedInMainMenu(char *buttonName, int value);
	void Menu::buttonPressedInSubMenu(char *buttonName, int value);


};



#endif /* MENU_H_ */
