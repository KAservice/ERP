#ifndef UREM_DMSprProducerDefectGrpCFH                  
#define UREM_DMSprProducerDefectGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerDefectGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerDefectGrpCF();                                                           
   ~TREM_DMSprProducerDefectGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
