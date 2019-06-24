#ifndef UREM_DMSprProducerConditionGrpCFH                  
#define UREM_DMSprProducerConditionGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerConditionGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerConditionGrpCF();                                                           
   ~TREM_DMSprProducerConditionGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
