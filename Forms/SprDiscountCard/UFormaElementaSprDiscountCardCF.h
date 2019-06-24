#ifndef UFormaElementaSprDiscountCardCFH                  
#define UFormaElementaSprDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprDiscountCardCF();                                                           
   ~TFormaElementaSprDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
