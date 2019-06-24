#ifndef UFormaElementaSprStrObjectCFH                  
#define UFormaElementaSprStrObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprStrObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprStrObjectCF();                                                           
   ~TFormaElementaSprStrObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
