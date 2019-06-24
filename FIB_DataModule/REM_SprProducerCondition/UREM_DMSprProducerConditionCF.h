#ifndef UREM_DMSprProducerConditionCFH                  
#define UREM_DMSprProducerConditionCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerConditionCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerConditionCF();                                                           
   ~TREM_DMSprProducerConditionCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
