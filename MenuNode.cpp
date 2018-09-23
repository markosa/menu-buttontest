/*
 * MenuNode.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: markos
 */

#include "MenuNode.h"
#include "Button.h"
#include "Configuration.h"

MenuNode::MenuNode(char* name) {
	this->namePtr = name;
	this->button = NULL;
	this->right = NULL;
	this->left = NULL;
}

MenuNode::MenuNode(char* name, Button *button) {
	this->namePtr = name;
	this->button = button;
	this->right = NULL;
	this->left = NULL;
}


void MenuNode::setButton(Button *button) {
	this->button = button;
}
void MenuNode::setLeftNode(MenuNode *node) {
	this->left = node;
}
void MenuNode::setRightNode(MenuNode *node) {
	this->right = node;
}

char* MenuNode::getName() {
	return this->namePtr;
}

MenuNode* MenuNode::getRightNode() {
	return this->right;
}

MenuNode* MenuNode::getLeftNode() {
	return this->left;
}

void MenuNode::addRightNode(MenuNode *node) {
	MenuNode *last = getLastNode(this);
	debug_print("addRightNode: Setting %s->right=%s \n",last->getName(),node->getName() );

	last->right = node;

}
void MenuNode::addLeftNode(MenuNode *node) {
	MenuNode *first = getFirstNode(this);
	debug_print("addLeftNode: Setting %s->left=%s \n",first->getName(),node->getName() );
	first->left = node;

}

MenuNode* MenuNode::getFirstNode(MenuNode *node) {
	if (node->left == NULL) {
		debug_print("getFirstNode: node->left == NULL returning: %s \n", node->getName());
		return node;
	}
	return getFirstNode(node->left);
}

MenuNode* MenuNode::getLastNode(MenuNode *node) {
	if (node->right == NULL)
		return node;

	return getLastNode(node->right);
}
