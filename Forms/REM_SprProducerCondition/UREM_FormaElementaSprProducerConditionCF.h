#ifndef UREM_FormaElementaSprProducerConditionCFH                  
#define UREM_FormaElementaSprProducerConditionCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprProducerConditionCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprProducerConditionCF();                                                           
   ~TREM_FormaElementaSprProducerConditionCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
