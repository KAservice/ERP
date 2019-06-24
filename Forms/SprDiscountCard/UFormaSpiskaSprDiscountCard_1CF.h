#ifndef UFormaSpiskaSprDiscountCard_1CFH                  
#define UFormaSpiskaSprDiscountCard_1CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprDiscountCard_1CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprDiscountCard_1CF();                                                           
   ~TFormaSpiskaSprDiscountCard_1CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
