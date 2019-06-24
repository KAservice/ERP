#ifndef UREM_FormaDocVidachaHWCFH                  
#define UREM_FormaDocVidachaHWCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocVidachaHWCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocVidachaHWCF();                                                           
   ~TREM_FormaDocVidachaHWCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
