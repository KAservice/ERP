#ifndef UFormaElementaSprObjectCFH                  
#define UFormaElementaSprObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprObjectCF();                                                           
   ~TFormaElementaSprObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
