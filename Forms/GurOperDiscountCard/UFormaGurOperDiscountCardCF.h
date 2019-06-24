#ifndef UFormaGurOperDiscountCardCFH                  
#define UFormaGurOperDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurOperDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurOperDiscountCardCF();                                                           
   ~TFormaGurOperDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
