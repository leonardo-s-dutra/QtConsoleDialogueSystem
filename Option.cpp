#include "Option.h"

Option::Option(QObject* parent) : QObject(parent)
{
    setText(0);
    setDestinationID(-1);
}

Option::Option(QString text, int destinationID, QObject* parent) : QObject(parent)
{
    setText(text);
    setDestinationID(destinationID);
}

QString Option::getText() const
{
    return this->text;
}

int Option::getDestinationID() const
{
    return this->destinationID;
}

void Option::setText(QString text)
{
    this->text = text;
}

void Option::setDestinationID(int destinationID)
{
    this->destinationID = destinationID;
}
