#ifndef UREM_DMSprProducerSectionCFH                  
#define UREM_DMSprProducerSectionCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerSectionCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerSectionCF();                                                           
   ~TREM_DMSprProducerSectionCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
