#ifndef UDMSprVidDiscountCardCFH                  
#define UDMSprVidDiscountCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprVidDiscountCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprVidDiscountCardCF();                                                           
   ~TDMSprVidDiscountCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
