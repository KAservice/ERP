#ifndef UREM_DMSprProducerNeisprCFH                  
#define UREM_DMSprProducerNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerNeisprCF();                                                           
   ~TREM_DMSprProducerNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
