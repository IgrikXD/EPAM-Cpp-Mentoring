#include "BaloonDataContainer.h"

BaloonDataContainer::BaloonDataContainer(QObject * parent) : QObject{parent} { }

int BaloonDataContainer::addSondeId(const QString & src_sonde_id) {

    for(QString & i : m_sondes_id)
        if (i == src_sonde_id)
            return 0;

    m_sondes_id.append(src_sonde_id);
    return 1;

}

QStringList BaloonDataContainer::getSondesId(void) const {
    return m_sondes_id;
}

void BaloonDataContainer::receiveId(const QString src_new_id) {
    if (addSondeId(src_new_id))
        emit idChanged();
}

void BaloonDataContainer::writeToFile(const QString & src_filename) {

    QFile file(src_filename);

    if (file.open(QIODevice::WriteOnly)){
        
        QTextStream out(&file);
        
        for(const QString & id : m_sondes_id) 
            out << id << endl;
        
        file.close();
    }
    else {
        qInfo() << "Error opening file " << src_filename << " for writing!";
    }
    
}
