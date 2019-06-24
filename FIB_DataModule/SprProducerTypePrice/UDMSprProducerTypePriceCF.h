#ifndef UDMSprProducerTypePriceCFH                  
#define UDMSprProducerTypePriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprProducerTypePriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprProducerTypePriceCF();                                                           
   ~TDMSprProducerTypePriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
