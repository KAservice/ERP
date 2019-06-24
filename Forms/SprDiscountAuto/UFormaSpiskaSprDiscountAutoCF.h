#ifndef UFormaSpiskaSprDiscountAutoCFH                  
#define UFormaSpiskaSprDiscountAutoCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprDiscountAutoCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprDiscountAutoCF();                                                           
   ~TFormaSpiskaSprDiscountAutoCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
