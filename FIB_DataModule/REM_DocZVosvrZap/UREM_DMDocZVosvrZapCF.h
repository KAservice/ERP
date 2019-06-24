#ifndef UREM_DMDocZVosvrZapCFH                  
#define UREM_DMDocZVosvrZapCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZVosvrZapCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZVosvrZapCF();                                                           
   ~TREM_DMDocZVosvrZapCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
