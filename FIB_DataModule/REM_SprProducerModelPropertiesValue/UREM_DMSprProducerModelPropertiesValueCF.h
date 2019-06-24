#ifndef UREM_DMSprProducerModelPropertiesValueCFH                  
#define UREM_DMSprProducerModelPropertiesValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerModelPropertiesValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerModelPropertiesValueCF();                                                           
   ~TREM_DMSprProducerModelPropertiesValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
