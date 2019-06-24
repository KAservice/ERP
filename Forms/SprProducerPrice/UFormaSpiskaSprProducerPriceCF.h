#ifndef UFormaSpiskaSprProducerPriceCFH                  
#define UFormaSpiskaSprProducerPriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprProducerPriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprProducerPriceCF();                                                           
   ~TFormaSpiskaSprProducerPriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
