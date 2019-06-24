#ifndef UDMSprProducerPriceCFH                  
#define UDMSprProducerPriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprProducerPriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprProducerPriceCF();                                                           
   ~TDMSprProducerPriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
