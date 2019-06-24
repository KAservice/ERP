#ifndef UREM_DMSprProducerModelInfBlockCFH                  
#define UREM_DMSprProducerModelInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerModelInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerModelInfBlockCF();                                                           
   ~TREM_DMSprProducerModelInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
