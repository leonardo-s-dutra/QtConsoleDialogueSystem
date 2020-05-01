#include "ConsoleDialogue.h"

ConsoleDialogue::ConsoleDialogue(QObject* parent = nullptr) : QObject(parent)
{

}

LOAD_STATUS ConsoleDialogue::loadDialogue(QString fileName)
{
    QDomDocument document;

    LOAD_STATUS loadStatus = XMLManager::checkFile(fileName, &document);

    if(loadStatus != OK)
        return loadStatus;

    QDomElement dialogueRoot = document.firstChildElement();
    QDomNodeList domNodes = dialogueRoot.elementsByTagName("Node");

    for(int i = 0; i < domNodes.count(); i++)
    {
        QDomElement elementNode = domNodes.at(i).toElement();

        LOAD_STATUS nodeStatus = XMLManager::checkNode(&elementNode);

        if (nodeStatus != OK)
        {
            foreach (Node* node, nodes)
                delete node;

            nodes.clear();
            return nodeStatus;
        }

        Node* dialogueNode = new Node(this);
        dialogueNode->setID(elementNode.attribute("ID").toInt());
        dialogueNode->setText(elementNode.attribute("Text"));
        addNode(dialogueNode);

        QDomNodeList domOptions = elementNode.elementsByTagName("Option");

        for (int j = 0; j < domOptions.count(); j++)
        {
            QDomElement elementOption = domOptions.at(j).toElement();

            LOAD_STATUS optionStatus = XMLManager::checkOption(&elementOption);

            if (optionStatus != OK)
            {
                foreach (Node* node, nodes)
                    delete node;

                nodes.clear();
                return nodeStatus;
            }

            Option* dialogueOption = new Option(dialogueNode);
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
