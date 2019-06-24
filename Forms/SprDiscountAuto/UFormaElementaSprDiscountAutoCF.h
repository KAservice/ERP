#ifndef UFormaElementaSprDiscountAutoCFH                  
#define UFormaElementaSprDiscountAutoCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprDiscountAutoCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprDiscountAutoCF();                                                           
   ~TFormaElementaSprDiscountAutoCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
