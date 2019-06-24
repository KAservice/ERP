#ifndef UREM_DMDocVosvratDileruCFH                  
#define UREM_DMDocVosvratDileruCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVosvratDileruCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVosvratDileruCF();                                                           
   ~TREM_DMDocVosvratDileruCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
