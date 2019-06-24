#ifndef UDMDocVipBankaCFH                  
#define UDMDocVipBankaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocVipBankaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocVipBankaCF();                                                           
   ~TDMDocVipBankaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
