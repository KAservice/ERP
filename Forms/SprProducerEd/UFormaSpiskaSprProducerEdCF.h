#ifndef UFormaSpiskaSprProducerEdCFH                  
#define UFormaSpiskaSprProducerEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprProducerEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprProducerEdCF();                                                           
   ~TFormaSpiskaSprProducerEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
