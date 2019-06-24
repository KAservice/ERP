#ifndef UFormaElementaSprAddressRayonCFH                  
#define UFormaElementaSprAddressRayonCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprAddressRayonCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprAddressRayonCF();                                                           
   ~TFormaElementaSprAddressRayonCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
