#ifndef UFormaElementaSprProducerCFH                  
#define UFormaElementaSprProducerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprProducerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprProducerCF();                                                           
   ~TFormaElementaSprProducerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
