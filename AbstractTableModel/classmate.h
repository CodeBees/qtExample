#ifndef PARAMTABLEVIEWMODEL_H
#define PARAMTABLEVIEWMODEL_H


#include <QAbstractTableModel>


class ClassMate
{
public:
	ClassMate(QString name, QString sex)
	{
		name_ = name;
		sex_ = sex;
	}

public:
	QString name_;
	QString sex_;
};



class ClassMateTableModel : public QAbstractTableModel
{
public:
	ClassMateTableModel();

	virtual QHash<int, QByteArray> roleNames() const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
	QList<ClassMate> classMateList_;
	QHash<int, QByteArray> roleNames_;
};

#endif // PARAMTABLEVIEWMODEL_H
