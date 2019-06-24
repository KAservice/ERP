#ifndef UDMSprDiscountCard_1CFH                  
#define UDMSprDiscountCard_1CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprDiscountCard_1CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprDiscountCard_1CF();                                                           
   ~TDMSprDiscountCard_1CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
