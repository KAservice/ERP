#ifndef UREM_DMSprProducerNeisprGrpCFH                  
#define UREM_DMSprProducerNeisprGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprProducerNeisprGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprProducerNeisprGrpCF();                                                           
   ~TREM_DMSprProducerNeisprGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
