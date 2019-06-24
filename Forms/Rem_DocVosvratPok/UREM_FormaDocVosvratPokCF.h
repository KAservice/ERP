#ifndef UREM_FormaDocVosvratPokCFH                  
#define UREM_FormaDocVosvratPokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVosvratPokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVosvratPokCF();                                                           
   ~TREM_FormaDocVosvratPokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
