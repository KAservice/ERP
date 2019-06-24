#ifndef UREM_DMDocVosvratIsSCCFH                  
#define UREM_DMDocVosvratIsSCCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVosvratIsSCCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVosvratIsSCCF();                                                           
   ~TREM_DMDocVosvratIsSCCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
