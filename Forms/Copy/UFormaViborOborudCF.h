#ifndef UFormaViborOborudCFH                  
#define UFormaViborOborudCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaViborOborudCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaViborOborudCF();                                                           
   ~TFormaViborOborudCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
