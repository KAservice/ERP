#ifndef UDMSprAddressRayonCFH                  
#define UDMSprAddressRayonCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprAddressRayonCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprAddressRayonCF();                                                           
   ~TDMSprAddressRayonCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
