#ifndef UDMSprProducerEdCFH                  
#define UDMSprProducerEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprProducerEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprProducerEdCF();                                                           
   ~TDMSprProducerEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
