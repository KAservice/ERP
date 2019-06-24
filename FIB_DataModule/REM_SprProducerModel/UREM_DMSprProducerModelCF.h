#ifndef UREM_DMSprProducerModelCFH                  
#define UREM_DMSprProducerModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerModelCF();                                                           
   ~TREM_DMSprProducerModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
