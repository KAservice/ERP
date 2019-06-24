#ifndef UDMSprAddressNasPunktCFH                  
#define UDMSprAddressNasPunktCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprAddressNasPunktCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprAddressNasPunktCF();                                                           
   ~TDMSprAddressNasPunktCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
