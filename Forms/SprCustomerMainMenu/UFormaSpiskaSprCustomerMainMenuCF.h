#ifndef UFormaSpiskaSprCustomerMainMenuCFH                  
#define UFormaSpiskaSprCustomerMainMenuCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprCustomerMainMenuCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprCustomerMainMenuCF();                                                           
   ~TFormaSpiskaSprCustomerMainMenuCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
