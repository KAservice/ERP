#ifndef UFormaSpiskaSprCustomerUserCFH                  
#define UFormaSpiskaSprCustomerUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprCustomerUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprCustomerUserCF();                                                           
   ~TFormaSpiskaSprCustomerUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
