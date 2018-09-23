/*
 * Menu.cpp
 *
 *  Created on: Sep 23, 2018
 *      Author: markos
 */


#include <stdio.h>
#include "Configuration.h"
#include "Menu.h"


Menu::Menu() {
	currentNode=NULL;
	nodeCount=0;
}


void Menu::addMenuNode(MenuNode *node) {
	if (nodeCount >= MENU_MAX_NODES) {
		debug_print("addMenuNode: Max node count reached %d", MENU_MAX_NODES);
		return;
	}

	this->nodes[nodeCount] = node;
	nodeCount++;

}
