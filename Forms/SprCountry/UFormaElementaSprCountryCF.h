#ifndef UFormaElementaSprCountryCFH                  
#define UFormaElementaSprCountryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprCountryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprCountryCF();                                                           
   ~TFormaElementaSprCountryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
