#pragma once

#include <QtCore>
#include <qtextstream.h>
#include "Option.h"

static QTextStream in(stdin);
static QTextStream out(stdout);


class Node
{
public:
	Node();
	Node(QString text);

	int run();

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

