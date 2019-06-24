#ifndef UFormaElementaSprProduceCFH                  
#define UFormaElementaSprProduceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprProduceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprProduceCF();                                                           
   ~TFormaElementaSprProduceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
