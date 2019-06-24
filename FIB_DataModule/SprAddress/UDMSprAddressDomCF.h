#ifndef UDMSprAddressDomCFH                  
#define UDMSprAddressDomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprAddressDomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprAddressDomCF();                                                           
   ~TDMSprAddressDomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
