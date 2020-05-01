#include "Node.h"

Node::Node(QObject* parent) : QObject(parent)
{
	setID(-1);
	setText(0);
}

Node::Node(QString text, QObject* parent) : QObject(parent)
{
	setID(-1);
	setText(text);
}

int Node::run()
{
    int key = 0;

    out << Qt::endl << getText() << Qt::endl;

    if (options.size() == 0)
        return -1;

    out << "----------------------------------------" << Qt::endl;

    for (int i = 0; i < options.size(); i++)
        out << i + 1 << " - " << options[i]->getText() << Qt::endl;

    out << "----------------------------------------" << Qt::endl;

    while (key < 1 || key > options.size())
    {
        out << "Enter an option: " << flush;
        in >> key;
    }

    return options[key - 1]->getDestinationID();
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
