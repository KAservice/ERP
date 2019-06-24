#ifndef UREM_FormaDocZAktPrCFH                  
#define UREM_FormaDocZAktPrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZAktPrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZAktPrCF();                                                           
   ~TREM_FormaDocZAktPrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
