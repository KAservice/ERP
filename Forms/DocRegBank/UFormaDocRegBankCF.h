#ifndef UFormaDocRegBankCFH                  
#define UFormaDocRegBankCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegBankCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegBankCF();                                                           
   ~TFormaDocRegBankCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
