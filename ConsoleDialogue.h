#pragma once

#include <QtCore>
#include <QtXml/qdom.h>
#include "Node.h"
#include "status.h"

class ConsoleDialogue
{
public:
	ConsoleDialogue();

	LOAD_STATUS loadDialogue(QString fileName);
	void run();

	void addNode(Node* node);

private:
	QList<Node*> nodes;
};

