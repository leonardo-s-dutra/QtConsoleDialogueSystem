#include "ConsoleDialogue.h"

ConsoleDialogue::ConsoleDialogue()
{

}

LOAD_STATUS ConsoleDialogue::loadDialogue(QString fileName)
{
    QDomDocument* document = new QDomDocument();

    LOAD_STATUS loadStatus = XMLManager::load(fileName, document);

    if(loadStatus != OK)
    {
        delete document;
        return loadStatus;
    }

    QDomElement dialogueRoot = document->firstChildElement();

    QDomNodeList domNodes = dialogueRoot.elementsByTagName("Node");

    for(int i = 0; i < domNodes.count(); i++)
    {
        QDomElement* elementNode = new QDomElement(domNodes.at(i).toElement());

        LOAD_STATUS nodeStatus = XMLManager::loadNode(elementNode);

        if (nodeStatus != OK)
        {
            foreach (Node* node, nodes)
                delete node;

            nodes.clear();
            delete elementNode;
            return nodeStatus;
        }

        Node* dialogueNode = new Node();
        dialogueNode->setID(elementNode->attribute("ID").toInt());
        dialogueNode->setText(elementNode->attribute("Text"));
        addNode(dialogueNode);

        QDomNodeList domOptions = elementNode->elementsByTagName("Option");

        for (int j = 0; j < domOptions.count(); j++)
        {
            QDomElement* elementOption = new QDomElement(domOptions.at(j).toElement());

            LOAD_STATUS optionStatus = XMLManager::loadOption(elementOption);

            if (optionStatus != OK)
            {
                foreach (Node* node, nodes)
                    delete node;

                nodes.clear();
                delete elementNode;
                return nodeStatus;
            }

            Option* dialogueOption = new Option();
            dialogueOption->setText(elementOption->attribute("Text"));
            dialogueOption->setDestinationID(elementOption->attribute("Destination").toInt());
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