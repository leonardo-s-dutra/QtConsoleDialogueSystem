#include "XMLManager.h"

LOAD_STATUS XMLManager::loadFile(QString fileName, QDomDocument* document)
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

LOAD_STATUS XMLManager::loadNode(QDomElement* element, Node* node)
{
    if (element->attribute("ID") == 0)
        return NO_NODE_ID;

    if (element->attribute("Text") == 0)
        return NO_NODE_TEXT;

    node->setID(element->attribute("ID").toInt());
    node->setText(element->attribute("Text"));

    return OK;
}

LOAD_STATUS XMLManager::loadOption(QDomElement* element, Option* option)
{
    if (element->attribute("Text") == 0)
        return NO_OPTION_TEXT;

    if (element->attribute("Destination") == 0)
        return NO_OPTION_DESTINATION_ID;

    option->setText(element->attribute("Text"));
    option->setDestinationID(element->attribute("Destination").toInt());

    return OK;
}
