#ifndef UFormaElementaSprProducerTypePriceCFH                  
#define UFormaElementaSprProducerTypePriceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprProducerTypePriceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprProducerTypePriceCF();                                                           
   ~TFormaElementaSprProducerTypePriceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
