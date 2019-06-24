#ifndef UDMSprCustomerUserGrpCFH                  
#define UDMSprCustomerUserGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprCustomerUserGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprCustomerUserGrpCF();                                                           
   ~TDMSprCustomerUserGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
