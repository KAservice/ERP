#ifndef UFormaDocVosvratPostCFH                  
#define UFormaDocVosvratPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocVosvratPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocVosvratPostCF();                                                           
   ~TFormaDocVosvratPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
