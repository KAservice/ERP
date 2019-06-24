#ifndef UFormaElementaSprBusinessOperCFH                  
#define UFormaElementaSprBusinessOperCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprBusinessOperCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprBusinessOperCF();                                                           
   ~TFormaElementaSprBusinessOperCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
