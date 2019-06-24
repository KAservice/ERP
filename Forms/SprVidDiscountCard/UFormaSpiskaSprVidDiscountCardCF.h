#ifndef UFormaSpiskaSprVidDiscountCardCFH                  
#define UFormaSpiskaSprVidDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprVidDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprVidDiscountCardCF();                                                           
   ~TFormaSpiskaSprVidDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
