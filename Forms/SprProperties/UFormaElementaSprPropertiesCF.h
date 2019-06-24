#ifndef UFormaElementaSprPropertiesCFH                  
#define UFormaElementaSprPropertiesCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprPropertiesCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprPropertiesCF();                                                           
   ~TFormaElementaSprPropertiesCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
