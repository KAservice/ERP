#ifndef UREM_FormaDocZVosvrZapCFH                  
#define UREM_FormaDocZVosvrZapCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZVosvrZapCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZVosvrZapCF();                                                           
   ~TREM_FormaDocZVosvrZapCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
