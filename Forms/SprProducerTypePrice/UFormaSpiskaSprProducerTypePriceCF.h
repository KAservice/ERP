#ifndef UFormaSpiskaSprProducerTypePriceCFH                  
#define UFormaSpiskaSprProducerTypePriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprProducerTypePriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprProducerTypePriceCF();                                                           
   ~TFormaSpiskaSprProducerTypePriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
