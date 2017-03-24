#include "classmate.h"
#include <QDebug>


ClassMateTableModel::ClassMateTableModel()
{

    int role = Qt::UserRole;
    roleNames_.insert(role++, "name");
    roleNames_.insert(role++, "sex");

    ClassMate cm0(QString::fromLocal8Bit("刘星")  , QString::fromLocal8Bit("男"));
    classMateList_.push_back(cm0);
    ClassMate cm1(QString::fromLocal8Bit("王蒙"), QString::fromLocal8Bit("女"));
    classMateList_.push_back(cm1);
    ClassMate cm2(QString::fromLocal8Bit("李大龙"), QString::fromLocal8Bit("男"));
    classMateList_.push_back(cm2);
    ClassMate cm3(QString::fromLocal8Bit("赵靓颖"), QString::fromLocal8Bit("女"));
    classMateList_.push_back(cm3);

}


//QModelIndex ClassMateTableModel::index(int row, int column, const QModelIndex &parent) const
//{
//
//}
//
//QModelIndex ClassMateTableModel::sibling(int row, int column, const QModelIndex &idx) const
//{
//
//}


int ClassMateTableModel::rowCount(const QModelIndex &parent) const
{
    return  classMateList_.count();
}

int ClassMateTableModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}


QHash<int, QByteArray> ClassMateTableModel::roleNames() const
{
    return roleNames_;
}

/**
 * \brief
 * \param index 单元格的位置
 * \param role 数据的角色
 * \return
 */


QVariant ClassMateTableModel::data(const QModelIndex &index, int role) const
{


    ClassMate cm= classMateList_[index.row()];

    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }


    switch (role - Qt::UserRole)
    {
    case 0:
        return cm.name_;
    case 1:
        return cm.sex_;
    default:
        return QVariant();
    }


    return QVariant();

}


