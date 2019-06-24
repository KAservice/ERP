#ifndef UREM_FormaDocAktCFH                  
#define UREM_FormaDocAktCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocAktCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocAktCF();                                                           
   ~TREM_FormaDocAktCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
