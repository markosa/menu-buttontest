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

struct NextNode {
	bool buttonFound = false;
	MenuNode* moveTo = NULL;
};

class Menu {

public:
	Menu();
	void addMenuNode(MenuNode *node);
	bool isMainMenu();
	void buttonPressed(char *buttonName, int value);
	void reset();
	void printNodeInfo();

private:
	MenuNode* nodes[MENU_MAX_NODES];
	int nodeCount;
	MenuNode* currentNode;
	void handleCallback(MenuNode *node, int value);
	NextNode findNextNode(char *buttonName);
};



#endif /* MENU_H_ */
