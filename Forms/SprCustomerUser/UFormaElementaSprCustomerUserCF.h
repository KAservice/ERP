#ifndef UFormaElementaSprCustomerUserCFH                  
#define UFormaElementaSprCustomerUserCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprCustomerUserCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprCustomerUserCF();                                                           
   ~TFormaElementaSprCustomerUserCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
