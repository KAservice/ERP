#ifndef UDMSprSellerCFH                  
#define UDMSprSellerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprSellerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprSellerCF();                                                           
   ~TDMSprSellerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
