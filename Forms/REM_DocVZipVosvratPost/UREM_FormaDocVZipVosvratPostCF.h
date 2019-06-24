#ifndef UREM_FormaDocVZipVosvratPostCFH                  
#define UREM_FormaDocVZipVosvratPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVZipVosvratPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVZipVosvratPostCF();                                                           
   ~TREM_FormaDocVZipVosvratPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
