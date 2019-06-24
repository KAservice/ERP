#ifndef UDMSprBankSchetCFH                  
#define UDMSprBankSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprBankSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprBankSchetCF();                                                           
   ~TDMSprBankSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
