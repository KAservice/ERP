#ifndef UDMSprAddressRegionCFH                  
#define UDMSprAddressRegionCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprAddressRegionCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprAddressRegionCF();                                                           
   ~TDMSprAddressRegionCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
