#ifndef UREM_DMDocZVidCFH                  
#define UREM_DMDocZVidCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZVidCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZVidCF();                                                           
   ~TREM_DMDocZVidCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
