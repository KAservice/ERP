#ifndef UREM_FormaElementaSprProducerModelPropertiesValueCFH                  
#define UREM_FormaElementaSprProducerModelPropertiesValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprProducerModelPropertiesValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprProducerModelPropertiesValueCF();                                                           
   ~TREM_FormaElementaSprProducerModelPropertiesValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
