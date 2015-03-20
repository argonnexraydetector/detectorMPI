
/*********************************************************************************
 *  This code developed at Argonne National Laboratory
 *  Author: Timothy Madden
 *  tmadden@anl.gov
 *
 *  March, 2015
 *
 *
 *********************************************************************************/



#ifndef mpiXpcs_H
#define mpiXpcs_H

#include "mpiengine.h"
#include "signalmessage.h"

#include "imm.h"

class mpiXpcs : public mpiEngine
{
public:
    mpiXpcs();
    ~mpiXpcs();


    virtual void beforeCalcs(mpiBcastMessage &message);
    virtual void beforeFirstCalc(mpiBcastMessage &message);
    virtual void afterCalcs(mpiBcastMessage &message);




virtual int parseMessage(mpiBcastMessage &message);




  virtual  int doImgCalcs(void);



    void subDark(int whichimg);
    void calcThresh(void);
    void reCalcThresh(void);
    void clearThresh(void);


    virtual int setupMPI2(int argc, char *argv[]);


    virtual void shutdownMPI2();



     unsigned short *sdark_image;
     unsigned short *sthresh_image;
    double *square_image;
    unsigned short *temp_image;

    imm my_imm;

};

#endif // mpiXpcs_H
