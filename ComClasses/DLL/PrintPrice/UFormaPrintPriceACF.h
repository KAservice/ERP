#ifndef UFormaPrintPriceACFH                  
#define UFormaPrintPriceACFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaPrintPriceACF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaPrintPriceACF();                                                           
   ~TFormaPrintPriceACF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
