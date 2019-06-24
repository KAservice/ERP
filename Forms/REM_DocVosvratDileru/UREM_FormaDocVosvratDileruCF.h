#ifndef UREM_FormaDocVosvratDileruCFH                  
#define UREM_FormaDocVosvratDileruCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVosvratDileruCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVosvratDileruCF();                                                           
   ~TREM_FormaDocVosvratDileruCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
