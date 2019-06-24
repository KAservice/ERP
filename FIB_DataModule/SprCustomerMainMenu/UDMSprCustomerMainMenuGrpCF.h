#ifndef UDMSprCustomerMainMenuGrpCFH                  
#define UDMSprCustomerMainMenuGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCustomerMainMenuGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCustomerMainMenuGrpCF();                                                           
   ~TDMSprCustomerMainMenuGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
