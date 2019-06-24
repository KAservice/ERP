#ifndef UFormaDocRealRoznForCashierCFH                  
#define UFormaDocRealRoznForCashierCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRealRoznForCashierCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRealRoznForCashierCF();                                                           
   ~TFormaDocRealRoznForCashierCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
