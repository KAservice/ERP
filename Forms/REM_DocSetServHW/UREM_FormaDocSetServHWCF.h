#ifndef UREM_FormaDocSetServHWCFH                  
#define UREM_FormaDocSetServHWCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocSetServHWCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocSetServHWCF();                                                           
   ~TREM_FormaDocSetServHWCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
