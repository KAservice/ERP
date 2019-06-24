#ifndef UREM_DMDocVidachaHWCFH                  
#define UREM_DMDocVidachaHWCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVidachaHWCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVidachaHWCF();                                                           
   ~TREM_DMDocVidachaHWCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
