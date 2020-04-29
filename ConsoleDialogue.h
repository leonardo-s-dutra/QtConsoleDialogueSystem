#pragma once

#include <QtCore>
#include "Node.h"


class ConsoleDialogue
{
public:
	ConsoleDialogue();

	void run();

	void addNode(Node* node);

private:
	QList<Node*> nodes;
};

