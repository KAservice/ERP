#ifndef UREM_FormaDocVosvratIsSCCFH                  
#define UREM_FormaDocVosvratIsSCCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVosvratIsSCCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVosvratIsSCCF();                                                           
   ~TREM_FormaDocVosvratIsSCCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
