#ifndef UREM_FormaDocZOperCFH                  
#define UREM_FormaDocZOperCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZOperCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZOperCF();                                                           
   ~TREM_FormaDocZOperCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
