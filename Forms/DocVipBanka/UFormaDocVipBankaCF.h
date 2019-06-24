#ifndef UFormaDocVipBankaCFH                  
#define UFormaDocVipBankaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocVipBankaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocVipBankaCF();                                                           
   ~TFormaDocVipBankaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
