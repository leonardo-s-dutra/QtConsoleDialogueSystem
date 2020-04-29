#include "Node.h"

Node::Node()
{
	setID(-1);
	setText(0);
}

Node::Node(QString text)
{
	setID(-1);
	setText(text);
}

int Node::getID() const
{
    return this->ID;
}

QString Node::getText() const
{
    return this->text;
}

QList<Option*> Node::getOptions() const
{
    return this->options;
}

void Node::setID(int ID)
{
    this->ID = ID;
}

void Node::setText(QString text)
{
    this->text = text;
}

void Node::addOption(Option* option)
{
    this->options.append(option);
}