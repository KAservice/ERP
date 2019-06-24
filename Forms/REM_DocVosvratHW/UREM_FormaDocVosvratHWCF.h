#ifndef UREM_FormaDocVosvratHWCFH                  
#define UREM_FormaDocVosvratHWCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVosvratHWCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVosvratHWCF();                                                           
   ~TREM_FormaDocVosvratHWCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
