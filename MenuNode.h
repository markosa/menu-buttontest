/*
 * MenuNode.h
 *
 *  Created on: Sep 20, 2018
 *      Author: markos
 */

#ifndef MENUNODE_H_
#define MENUNODE_H_

#include "Button.h"
#include <stdio.h>

class MenuNode {

public:
	MenuNode(char *name);
	MenuNode(char *name, Button *button);

	void setLeftNode(MenuNode *node);
	void setRightNode(MenuNode *node);
	void setButton(Button *button);
	void addRightNode(MenuNode *node);
	void addLeftNode(MenuNode *node);
	char* getName();
	MenuNode *getLeftNode();
	MenuNode *getRightNode();
	void (*callback) (const int &value);


private:
	MenuNode* getFirstNode(MenuNode *node);
	MenuNode* getLastNode(MenuNode *node);

	char *namePtr;
	MenuNode *left;
	MenuNode *right;
	Button *button;
};

#endif /* MENUNODE_H_ */
