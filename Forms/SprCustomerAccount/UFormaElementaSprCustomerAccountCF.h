#ifndef UFormaElementaSprCustomerAccountCFH                  
#define UFormaElementaSprCustomerAccountCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprCustomerAccountCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprCustomerAccountCF();                                                           
   ~TFormaElementaSprCustomerAccountCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
