#ifndef UFormaViborBVNomCFH                  
#define UFormaViborBVNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaViborBVNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaViborBVNomCF();                                                           
   ~TFormaViborBVNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
