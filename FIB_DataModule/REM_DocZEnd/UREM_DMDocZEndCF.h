#ifndef UREM_DMDocZEndCFH                  
#define UREM_DMDocZEndCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZEndCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZEndCF();                                                           
   ~TREM_DMDocZEndCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
