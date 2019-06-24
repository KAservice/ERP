#ifndef UDMRegAdvanceCustomerCFH                  
#define UDMRegAdvanceCustomerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMRegAdvanceCustomerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMRegAdvanceCustomerCF();                                                           
   ~TDMRegAdvanceCustomerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
