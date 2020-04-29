#include "XMLManager.h"

LOAD_STATUS XMLManager::load(QString fileName, QDomDocument* document)
{
	QFile* file = new QFile(fileName);

    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        return INVALID_FILE;

    if (!document->setContent(file))
    {
        file->close();
        return INVALID_CONTENT;
    }

    file->close();

    return OK;
}

LOAD_STATUS XMLManager::loadNode(QDomElement* node)
{
    if (node->attribute("ID") == 0)
        return NO_NODE_ID;

    if (node->attribute("Text") == 0)
        return NO_NODE_TEXT;

    return OK;
}

LOAD_STATUS XMLManager::loadOption(QDomElement* option)
{
    if (option->attribute("Text") == 0)
        return NO_OPTION_TEXT;

    if (option->attribute("Destination") == 0)
        return NO_OPTION_DESTINATION_ID;

    return OK;
}