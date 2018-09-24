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

void Menu::buttonPressedInMainMenu(char *buttonName, int value) {
	for (int i = 0; i < nodeCount; i++) {
		MenuNode* node = nodes[i];

		if (node->button != NULL && strcmp(node->button->namePtr, buttonName)) {
			debug_print("buttonPressed: buttonName: %s value: %d",
					node->button->namePtr, value);

			if (node->callback != NULL)
				node->callback(value);
			else
				debug_print("Callback for node %s is NULL", node->namePtr);

			return;
		}
	}

	debug_print("No available button: %s in main menu", buttonName);
}
void Menu::buttonPressedInSubMenu(char *buttonName, int value) {
	if (this->currentNode->right != NULL) {
		if (this->currentNode->right->button != NULL) {
			if (strcmp(this->currentNode->right->button->namePtr, buttonName)) {
				this->currentNode->right->callback(value);
			}
		}
	}
}

void Menu::buttonPressed(char *buttonName, int value) {
	if (isMainMenu()) {
		this->buttonPressedInMainMenu(buttonName, value);
	} else {
		this->buttonPressedInSubMenu(buttonName, value);
	}
}
