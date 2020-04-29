#pragma once

#include <QtCore>


class Option
{
public:
	Option();
	Option(QString text, int destinationNodeID);

	QString getText() const;
	int getDestinationNodeID() const;

	void setText(QString text);
	void setDestinationNodeID(int destinationNodeID);

private:
	QString text;
	int destinationNodeID;
};

