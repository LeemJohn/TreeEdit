#pragma once

#include <QAbstractListModel>
namespace TaoCommon
{
    template <typename T>
    class TaoListModel : public QAbstractListModel
    {
    public:
        using Super = QAbstractListModel;

        TaoListModel(QObject *parent = nullptr);
        TaoListModel(const QList<T> &nodeList, QObject *parent = nullptr);

        const QList<T> &nodeList() const
        {
            return m_nodeList;
        }
        void setNodeList(const QList<T> &nodeList);

        int rowCount(const QModelIndex &parent) const override;

        QVariant data(const QModelIndex &index, int role) const override;
        bool setData(const QModelIndex &index, const QVariant &value, int role) override;

        Qt::ItemFlags flags(const QModelIndex &index) const override;

        bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
        bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

        Qt::DropActions supportedDropActions() const override;

    private:
        QList<T> m_nodeList;
    };
} // namespace TaoCommon
