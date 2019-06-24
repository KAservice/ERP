#ifndef UDMSprProducerCFH                  
#define UDMSprProducerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprProducerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprProducerCF();                                                           
   ~TDMSprProducerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
