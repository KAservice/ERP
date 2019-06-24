#ifndef UREM_DMDocVosvratHWCFH                  
#define UREM_DMDocVosvratHWCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVosvratHWCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVosvratHWCF();                                                           
   ~TREM_DMDocVosvratHWCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
