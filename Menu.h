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

class Menu {

public:
	Menu();
	void addMenuNode(MenuNode *node);

	void reset();


private:
	MenuNode* nodes[MENU_MAX_NODES];
	int nodeCount;
	MenuNode* currentNode;


};



#endif /* MENU_H_ */
