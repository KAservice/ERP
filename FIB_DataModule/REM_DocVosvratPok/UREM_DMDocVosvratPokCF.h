#ifndef UREM_DMDocVosvratPokCFH                  
#define UREM_DMDocVosvratPokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVosvratPokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVosvratPokCF();                                                           
   ~TREM_DMDocVosvratPokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
