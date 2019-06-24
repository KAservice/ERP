#ifndef UDMDocVosvratPokCFH                  
#define UDMDocVosvratPokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocVosvratPokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocVosvratPokCF();                                                           
   ~TDMDocVosvratPokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
