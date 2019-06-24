#ifndef UREM_FormaDocZEndCFH                  
#define UREM_FormaDocZEndCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZEndCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZEndCF();                                                           
   ~TREM_FormaDocZEndCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
