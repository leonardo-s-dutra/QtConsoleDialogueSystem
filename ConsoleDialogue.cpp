#include "ConsoleDialogue.h"

ConsoleDialogue::ConsoleDialogue(QObject* parent) : QObject(parent)
{

}

LOAD_STATUS ConsoleDialogue::loadDialogue(QString fileName)
{
    QDomDocument document;

    LOAD_STATUS fileStatus = XMLManager::loadFile(fileName, &document);

    if(fileStatus != OK)
        return fileStatus;

    QDomElement dialogueRoot = document.firstChildElement();
    QDomNodeList domNodes = dialogueRoot.elementsByTagName("Node");

    for(int i = 0; i < domNodes.count(); i++)
    {
        QDomElement elementNode = domNodes.at(i).toElement();
        Node* dialogueNode = new Node(this);

        LOAD_STATUS nodeStatus = XMLManager::loadNode(elementNode, dialogueNode);

        if (nodeStatus != OK)
        {
            delete dialogueNode;
            return nodeStatus;
        }

        addNode(dialogueNode);

        QDomNodeList domOptions = elementNode.elementsByTagName("Option");

        for (int j = 0; j < domOptions.count(); j++)
        {
            QDomElement elementOption = domOptions.at(j).toElement();
            Option* dialogueOption = new Option(dialogueNode);

            LOAD_STATUS optionStatus = XMLManager::loadOption(elementOption, dialogueOption);

            if (optionStatus != OK)
            {
                delete dialogueNode;
                return nodeStatus;
            }

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

    out << Qt::endl;
}

void ConsoleDialogue::addNode(Node* node)
{
    nodes.append(node);

    int ID = nodes.indexOf(node);

    node->setID(ID);
}
