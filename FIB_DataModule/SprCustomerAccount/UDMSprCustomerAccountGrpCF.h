#ifndef UDMSprCustomerAccountGrpCFH                  
#define UDMSprCustomerAccountGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCustomerAccountGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCustomerAccountGrpCF();                                                           
   ~TDMSprCustomerAccountGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
