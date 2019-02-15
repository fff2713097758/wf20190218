#ifndef TABLE_H
#define TABLE_H

#include <QtGui>
#include <QTableWidget>
#include <QStyledItemDelegate>
#include <QHeaderView>

class Table : public QTableWidget
{
    Q_OBJECT
public:
    Table(QWidget *parent = 0);
    ~Table();
    void setColumnValue(const int &columnSum, const QStringList &header);   //set header value
    void setHeaderWidth(const int &index, const int &width);    //set header and column widhth for each index
    void setHeaderHeight(const int &height);                    //set header height

    void addRowValue(const int &height, const QStringList &value, const QIcon &fileIcon);
    void setRowH(const int &index, const int &height);
    void setItemFixed(bool flag);
    bool getSelectedRow(QList<int> &rowList);

protected:
    void contextMenuEvent(QContextMenuEvent *event);
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
    void keyPressEvent(QKeyEvent *event);

private:
    void createActions();

private slots:
    void slotItemEntered(QTableWidgetItem *item);
    void slotActionRename();
    void slotItemSelectionChanged();

private:
    int tableWidth;
    int tableHeight;
    QList<int>rowHeghtList;
    QList<int>rowWidthList;

    QMenu *popMenu;
    QAction *actionName;
    QAction *actionSize;
    QAction *actionType;
    QAction *actionDate;
    QAction *actionOpen;
    QAction *actionDownload;
    QAction *actionFlush;
    QAction *actionDelete;
    QAction *actionRename;
    QAction *actionCreateFolder;
    QTableWidgetItem *rightClickedItem;
    QMap<QTableWidgetItem *, QString>fileMap;
    bool dupFlag;
};

// custom item delegate class
class NoFocusDelegate : public QStyledItemDelegate
{
protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};


#endif // TABLE_H
