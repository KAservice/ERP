#ifndef UDMSprProducerNomCFH                  
#define UDMSprProducerNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprProducerNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprProducerNomCF();                                                           
   ~TDMSprProducerNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
