#pragma once

#include <QtCore>


class Option : public QObject
{
public:
	Option(QObject* parent);
	Option(QString text, int destinationID, QObject* parent);

	QString getText() const;
	int getDestinationID() const;

	void setText(QString text);
	void setDestinationID(int destinationID);

private:
	QString text;
	int destinationID;
};

