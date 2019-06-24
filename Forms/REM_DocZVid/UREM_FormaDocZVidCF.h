#ifndef UREM_FormaDocZVidCFH                  
#define UREM_FormaDocZVidCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZVidCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZVidCF();                                                           
   ~TREM_FormaDocZVidCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
