#ifndef UDMSprAddressKVCFH                  
#define UDMSprAddressKVCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprAddressKVCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprAddressKVCF();                                                           
   ~TDMSprAddressKVCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
