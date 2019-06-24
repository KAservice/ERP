#ifndef UDMDocRegBankCFH                  
#define UDMDocRegBankCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRegBankCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRegBankCF();                                                           
   ~TDMDocRegBankCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
