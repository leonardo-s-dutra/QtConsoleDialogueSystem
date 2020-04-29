#include "ConsoleDialogue.h"

ConsoleDialogue::ConsoleDialogue()
{

}

void ConsoleDialogue::addNode(Node* node)
{
    nodes.append(node);

    int ID = nodes.indexOf(node);

    node->setID(ID);
}