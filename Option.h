#pragma once

#include <QtCore>


class Option : public QObject
{
public:
	Option(QObject* parent = Q_NULLPTR);
	Option(QString text, int destinationID, QObject* parent = Q_NULLPTR);

	QString getText() const;
	int getDestinationID() const;

	void setText(QString text);
	void setDestinationID(int destinationID);

private:
	QString text;
	int destinationID;
};
