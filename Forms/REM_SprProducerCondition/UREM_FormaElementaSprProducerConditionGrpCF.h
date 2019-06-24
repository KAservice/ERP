#ifndef UREM_FormaElementaSprProducerConditionGrpCFH                  
#define UREM_FormaElementaSprProducerConditionGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprProducerConditionGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprProducerConditionGrpCF();                                                           
   ~TREM_FormaElementaSprProducerConditionGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
