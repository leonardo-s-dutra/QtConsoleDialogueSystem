#pragma once

#include <QtCore>
#include <QtXml/qdom.h>
#include "Node.h"
#include "Option.h"
#include "load_status.h"


class XMLManager
{
public:
	static LOAD_STATUS checkFile(QString fileName, QDomDocument* document);

	static LOAD_STATUS loadNode(QDomElement* element, Node* node);

	static LOAD_STATUS loadOption(QDomElement* element, Option* option);

private:
	XMLManager() {}
};

