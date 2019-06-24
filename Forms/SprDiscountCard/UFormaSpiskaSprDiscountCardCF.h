#ifndef UFormaSpiskaSprDiscountCardCFH                  
#define UFormaSpiskaSprDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprDiscountCardCF();                                                           
   ~TFormaSpiskaSprDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
