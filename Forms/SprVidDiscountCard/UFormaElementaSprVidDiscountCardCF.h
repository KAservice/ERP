#ifndef UFormaElementaSprVidDiscountCardCFH                  
#define UFormaElementaSprVidDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprVidDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprVidDiscountCardCF();                                                           
   ~TFormaElementaSprVidDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
