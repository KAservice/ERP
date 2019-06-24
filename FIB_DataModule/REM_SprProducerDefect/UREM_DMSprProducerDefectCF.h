#ifndef UREM_DMSprProducerDefectCFH                  
#define UREM_DMSprProducerDefectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerDefectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerDefectCF();                                                           
   ~TREM_DMSprProducerDefectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
