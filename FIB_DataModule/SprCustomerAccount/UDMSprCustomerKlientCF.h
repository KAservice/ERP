#ifndef UDMSprCustomerKlientCFH                  
#define UDMSprCustomerKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCustomerKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCustomerKlientCF();                                                           
   ~TDMSprCustomerKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
