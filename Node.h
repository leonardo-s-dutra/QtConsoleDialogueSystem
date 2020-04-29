#pragma once

#include <QtCore>
#include "Option.h"


class Node
{
public:
	Node();
	Node(QString text);

	int getID() const;
	QString getText() const;
	QList<Option*> getOptions() const;

	void setID(int ID);
	void setText(QString text);
	void addOption(Option* option);

private:
	int ID;
	QString text;
	QList<Option*> options;
};

