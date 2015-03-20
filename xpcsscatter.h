
/*********************************************************************************
 *  This code developed at Argonne National Laboratory
 *  Author: Timothy Madden
 *  tmadden@anl.gov
 *
 *  March, 2015
 *
 *
 *********************************************************************************/



#ifndef xpcsScatter_H
#define xpcsScatter_H

#include "mpiScatter.h"

class xpcsScatter : public mpiScatter
{
public:
    xpcsScatter(
            mpiEngine *mpi,
            imageQueue &free,
            imageQueue &data);

    ~xpcsScatter();

public slots:
    virtual void    gotMPIGuiSettings(guiSignalMessage mes_);

protected:
    // called each time we defifo image from data queie on new image slot
    virtual void onDeFifo(imageQueueItem *item);
    // called just before we start defifo images on new image slot.
    virtual void beforeDeFifo(void);
    //after defifo and scatter on new image, just before mpi calcs are starrted,
    virtual void afterDeFifo(void);

};

#endif // xpcsScatter_H
