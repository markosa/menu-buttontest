/*
 * Menu.cpp
 *
 *  Created on: Sep 23, 2018
 *      Author: markos
 */

#include <stdio.h>
#include <string.h>

#include "Configuration.h"
#include "Menu.h"
#include <strings.h>

Menu::Menu() {
	currentNode = NULL;
	nodeCount = 0;
}

bool Menu::isMainMenu() {
	return (currentNode == NULL);
}

void Menu::addMenuNode(MenuNode *node) {
	if (nodeCount >= MENU_MAX_NODES) {
		debug_print("addMenuNode: Max node count reached %d", MENU_MAX_NODES);
		return;
	}

	this->nodes[nodeCount] = node;
	nodeCount++;

}

NextNode Menu::findNextNode(char *buttonName) {

	NextNode nextNode = NextNode();
	nextNode.buttonFound = false;

	if (isMainMenu()) {
		for (int i = 0; i < nodeCount; i++) {
			MenuNode *node = nodes[i];
			if (strcmp(node->getButton()->getNamePtr(), buttonName) == 0) {
				debug_print(
						"MAINMENU: Found main node matching pressed (node->getButton()->getNamePtr()) button %s\n",
						buttonName);
				nextNode.buttonFound = true;
				nextNode.moveTo = node;
			}
		}
	} else {
		if ((currentNode->getRightNode() != NULL)
				&& (currentNode->getRightNode()->getButton() != NULL)) {
			if (strcmp(currentNode->getRightNode()->getButton()->getNamePtr(),
					buttonName) == 0) {
				debug_print(
						"SUBMENU: Found sub node matching pressed (node->getButton()->getNamePtr()) button %s\n",
						buttonName);
				nextNode.buttonFound = true;
				nextNode.moveTo = currentNode->getRightNode();
			}
		}
	}

	debug_print("No node available for button %s", buttonName);

	return nextNode;
}

void Menu::buttonPressed(char *buttonName, int value) {
	NextNode moveTo = findNextNode(buttonName);

	if (moveTo)

	/* if (moveTo == NULL) {
	 // Return to main menu
	 currentNode=NULL;
	 return;
	 } */

	handleCallback(currentNode, value);

	// Move to node
	// currentNode=moveTo;

}

void Menu::handleCallback(MenuNode *node, int value) {
	if (node != NULL && node->callback != NULL) {
		node->callback(value);
	}
}

void Menu::printNodeInfo() {
	if (isMainMenu()) {
		printf("*********\n");
		printf("IN MAIN MENU - nodes available: \n");
		for (int i = 0; i < nodeCount; i++) {
			MenuNode* node = nodes[i];
			Button* button = node->getButton();
			printf("%d ** %s # %s \n", i, node->getName(),
					button->getNamePtr());
		}
		printf("*********\n");
	} else {
		printf("*********\n");
		printf("IN SUB MENU - node available: \n");
		Button* button = this->currentNode->getButton();
		printf("%s # %s \n", currentNode->getName(),
				currentNode->getButton()->getNamePtr());
		printf("*********\n");

	}

}
