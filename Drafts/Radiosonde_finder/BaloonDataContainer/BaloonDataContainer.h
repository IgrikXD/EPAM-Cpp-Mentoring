#ifndef BALOONDATACONTAINER_H
#define BALOONDATACONTAINER_H

#include <QObject>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class BaloonDataContainer : public QObject{
    Q_OBJECT
    Q_PROPERTY(QStringList id_list MEMBER m_sondes_id NOTIFY idChanged)
private:
    //Container that storing the ID list of all radiosondes.
    QStringList m_sondes_id;
public:
    BaloonDataContainer(QObject * parent = nullptr);
    //Adding a new radiosonde ID to the container.
    //Returns value:
    // 1 - if successfully;
    // 0 - if ID already exists;
    int addSondeId(const QString & src_sonde_id);
    //Returns a QStringList container that contains the ID of all radiosondes.
    QStringList getSondesId(void) const;
signals:
    //Report to QML layer about ID list changing
    void idChanged();
public slots:
    //Get string ID value from QML layer
    void receiveId(const QString src_new_id);
    //Write all ID values to local file
    void writeToFile(const QString & src_filename);
};

#endif // BALOONDATACONTAINER_H
