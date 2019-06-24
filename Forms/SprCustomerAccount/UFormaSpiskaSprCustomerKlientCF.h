#ifndef UFormaSpiskaSprCustomerKlientCFH                  
#define UFormaSpiskaSprCustomerKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprCustomerKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprCustomerKlientCF();                                                           
   ~TFormaSpiskaSprCustomerKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
