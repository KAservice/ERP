#ifndef UDMSprAddressStroenCFH                  
#define UDMSprAddressStroenCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprAddressStroenCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprAddressStroenCF();                                                           
   ~TDMSprAddressStroenCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
