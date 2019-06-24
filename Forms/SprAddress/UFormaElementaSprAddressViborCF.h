#ifndef UFormaElementaSprAddressViborCFH                  
#define UFormaElementaSprAddressViborCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprAddressViborCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprAddressViborCF();                                                           
   ~TFormaElementaSprAddressViborCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
