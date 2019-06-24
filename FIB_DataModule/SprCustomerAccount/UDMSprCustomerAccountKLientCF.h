#ifndef UDMSprCustomerAccountKLientCFH                  
#define UDMSprCustomerAccountKLientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCustomerAccountKLientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCustomerAccountKLientCF();                                                           
   ~TDMSprCustomerAccountKLientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
