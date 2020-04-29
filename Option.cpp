#include "Option.h"

Option::Option()
{
    setText(0);
    setDestinationNodeID(-1);
}

Option::Option(QString text, int destinationNodeID)
{
    setText(text);
    setDestinationNodeID(destinationNodeID);
}

QString Option::getText() const
{
    return this->text;
}

int Option::getDestinationNodeID() const
{
    return this->destinationNodeID;
}

void Option::setText(QString text)
{
    this->text = text;
}

void Option::setDestinationNodeID(int destinationNodeID)
{
    this->destinationNodeID = destinationNodeID;
}
