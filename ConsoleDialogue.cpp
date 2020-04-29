#include "ConsoleDialogue.h"

ConsoleDialogue::ConsoleDialogue()
{

}

LOAD_STATUS ConsoleDialogue::loadDialogue(QString fileName)
{
    QDomDocument document;

    QFile* file = new QFile(fileName);

    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        return INVALID_FILE;

    if (!document.setContent(file))
        return INVALID_CONTENT;

    file->close();

    QDomElement dialogueRoot = document.firstChildElement();

    QDomNodeList domNodes = dialogueRoot.elementsByTagName("Node");

    for (int i = 0; i < domNodes.count(); i++)
    {
        QDomElement elementNode = domNodes.at(i).toElement();

        if (elementNode.attribute("ID") == 0)
        {
            nodes.clear();
            return NO_NODE_ID;
        }

        if (elementNode.attribute("Text") == 0)
        {
            nodes.clear();
            return NO_NODE_TEXT;
        }

        Node* dialogueNode = new Node();
        dialogueNode->setID(elementNode.attribute("ID").toInt());
        dialogueNode->setText(elementNode.attribute("Text"));
        addNode(dialogueNode);

        QDomNodeList domOptions = elementNode.elementsByTagName("Option");

        for (int j = 0; j < domOptions.count(); j++)
        {
            QDomElement elementOption = domOptions.at(j).toElement();

            if (elementOption.attribute("Text") == 0)
            {
                nodes.clear();
                return NO_OPTION_TEXT;
            }

            if (elementOption.attribute("Destination") == 0)
            {
                nodes.clear();
                return NO_OPTION_DESTINATION_ID;
            }

            Option* dialogueOption = new Option();
            dialogueOption->setText(elementOption.attribute("Text"));
            dialogueOption->setDestinationID(elementOption.attribute("Destination").toInt());
            dialogueNode->addOption(dialogueOption);
        }
    }

    return OK;
}

void ConsoleDialogue::run()
{
    int currentID = 0;

    while (currentID != -1)
        currentID = nodes[currentID]->run();
}

void ConsoleDialogue::addNode(Node* node)
{
    nodes.append(node);

    int ID = nodes.indexOf(node);

    node->setID(ID);
}