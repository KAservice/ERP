#ifndef UFormaOperCreditCardCFH                  
#define UFormaOperCreditCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaOperCreditCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaOperCreditCardCF();                                                           
   ~TFormaOperCreditCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
