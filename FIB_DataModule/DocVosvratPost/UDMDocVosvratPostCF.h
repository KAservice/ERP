#ifndef UDMDocVosvratPostCFH                  
#define UDMDocVosvratPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocVosvratPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocVosvratPostCF();                                                           
   ~TDMDocVosvratPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
