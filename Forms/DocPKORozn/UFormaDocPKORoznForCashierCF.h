#ifndef UFormaDocPKORoznForCashierCFH                  
#define UFormaDocPKORoznForCashierCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocPKORoznForCashierCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocPKORoznForCashierCF();                                                           
   ~TFormaDocPKORoznForCashierCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
