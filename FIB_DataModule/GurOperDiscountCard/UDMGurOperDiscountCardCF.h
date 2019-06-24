#ifndef UDMGurOperDiscountCardCFH                  
#define UDMGurOperDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMGurOperDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMGurOperDiscountCardCF();                                                           
   ~TDMGurOperDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
