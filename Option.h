#pragma once

#include <QtCore>


class Option
{
public:
	Option();
	Option(QString text, int destinationID);

	QString getText() const;
	int getDestinationID() const;

	void setText(QString text);
	void setDestinationID(int destinationID);

private:
	QString text;
	int destinationID;
};

