#ifndef UREM_FormaSpiskaSprProducerModelInfBlockCFH                  
#define UREM_FormaSpiskaSprProducerModelInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprProducerModelInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprProducerModelInfBlockCF();                                                           
   ~TREM_FormaSpiskaSprProducerModelInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
