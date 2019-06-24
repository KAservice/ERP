#ifndef UFormaSpiskaSprBankSchetCFH                  
#define UFormaSpiskaSprBankSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprBankSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprBankSchetCF();                                                           
   ~TFormaSpiskaSprBankSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
