#ifndef UObjectCheckDiscountCFH                  
#define UObjectCheckDiscountCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TObjectCheckDiscountCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TObjectCheckDiscountCF();                                                           
   ~TObjectCheckDiscountCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
