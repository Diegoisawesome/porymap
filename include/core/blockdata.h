#ifndef BLOCKDATA_H
#define BLOCKDATA_H

#include "block.h"

#include <QObject>
#include <QByteArray>

class Blockdata : public QObject
{
    Q_OBJECT
public:
    explicit Blockdata(QObject *parent = nullptr);
    ~Blockdata() {
        if (blocks) delete blocks;
    }

public:
    QList<Block> *blocks = nullptr;
    void addBlock(uint16_t);
    void addBlock(Block);
    QByteArray serialize();
    void copyFrom(Blockdata*);
    Blockdata* copy();
    bool equals(Blockdata *);

signals:

public slots:
};

#endif // BLOCKDATA_H
