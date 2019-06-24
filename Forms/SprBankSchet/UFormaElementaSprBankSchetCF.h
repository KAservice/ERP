#ifndef UFormaElementaSprBankSchetCFH                  
#define UFormaElementaSprBankSchetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprBankSchetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprBankSchetCF();                                                           
   ~TFormaElementaSprBankSchetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
