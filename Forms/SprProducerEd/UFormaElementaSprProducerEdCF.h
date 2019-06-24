#ifndef UFormaElementaSprProducerEdCFH                  
#define UFormaElementaSprProducerEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprProducerEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprProducerEdCF();                                                           
   ~TFormaElementaSprProducerEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
