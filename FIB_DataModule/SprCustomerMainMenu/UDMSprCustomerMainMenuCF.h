#ifndef UDMSprCustomerMainMenuCFH                  
#define UDMSprCustomerMainMenuCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCustomerMainMenuCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCustomerMainMenuCF();                                                           
   ~TDMSprCustomerMainMenuCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
