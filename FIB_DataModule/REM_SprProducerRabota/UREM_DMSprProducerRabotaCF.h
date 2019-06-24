#ifndef UREM_DMSprProducerRabotaCFH                  
#define UREM_DMSprProducerRabotaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerRabotaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerRabotaCF();                                                           
   ~TREM_DMSprProducerRabotaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
