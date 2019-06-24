#ifndef UDMSprDiscountCardCFH                  
#define UDMSprDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprDiscountCardCF();                                                           
   ~TDMSprDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
