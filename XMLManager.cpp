#include "XMLManager.h"

LOAD_STATUS XMLManager::checkFile(QString fileName, QDomDocument* document)
{
    if (!fileName.endsWith(".xml"))
        return NOT_XML_EXTENSION;

	QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return INVALID_FILE;

    if (!document->setContent(&file))
    {
        file.close();
        return INVALID_CONTENT;
    }

    file.close();

    return OK;
}

LOAD_STATUS XMLManager::checkNode(QDomElement* node)
{
    if (node->attribute("ID") == 0)
        return NO_NODE_ID;

    if (node->attribute("Text") == 0)
        return NO_NODE_TEXT;

    return OK;
}

LOAD_STATUS XMLManager::checkOption(QDomElement* option)
{
    if (option->attribute("Text") == 0)
        return NO_OPTION_TEXT;

    if (option->attribute("Destination") == 0)
        return NO_OPTION_DESTINATION_ID;

    return OK;
}
