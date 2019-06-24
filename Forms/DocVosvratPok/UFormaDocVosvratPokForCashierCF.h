#ifndef UFormaDocVosvratPokForCashierCFH                  
#define UFormaDocVosvratPokForCashierCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocVosvratPokForCashierCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocVosvratPokForCashierCF();                                                           
   ~TFormaDocVosvratPokForCashierCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
