#pragma once

#include <QtCore>
#include <QtXml/qdom.h>
#include "Node.h"
#include "load_status.h"
#include "XMLManager.h"

class ConsoleDialogue : QObject
{
public:
	ConsoleDialogue(QObject* parent = nullptr);

	LOAD_STATUS loadDialogue(QString fileName);
	void run();

	void addNode(Node* node);

private:
	QList<Node*> nodes;
};

