#ifndef UREM_DMDocVZipVosvratPostCFH                  
#define UREM_DMDocVZipVosvratPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVZipVosvratPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVZipVosvratPostCF();                                                           
   ~TREM_DMDocVZipVosvratPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
