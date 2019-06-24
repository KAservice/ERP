#ifndef UFormaDocVosvratPokCFH                  
#define UFormaDocVosvratPokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocVosvratPokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocVosvratPokCF();                                                           
   ~TFormaDocVosvratPokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
