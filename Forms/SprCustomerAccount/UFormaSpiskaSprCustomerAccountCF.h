#ifndef UFormaSpiskaSprCustomerAccountCFH                  
#define UFormaSpiskaSprCustomerAccountCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprCustomerAccountCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprCustomerAccountCF();                                                           
   ~TFormaSpiskaSprCustomerAccountCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
