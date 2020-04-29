#include "ConsoleDialogue.h"

ConsoleDialogue::ConsoleDialogue()
{

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