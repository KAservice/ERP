#ifndef UREM_FormaSpiskaSprProducerModelPropertiesValueCFH                  
#define UREM_FormaSpiskaSprProducerModelPropertiesValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprProducerModelPropertiesValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprProducerModelPropertiesValueCF();                                                           
   ~TREM_FormaSpiskaSprProducerModelPropertiesValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
