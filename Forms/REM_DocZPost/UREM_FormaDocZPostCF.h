#ifndef UREM_FormaDocZPostCFH                  
#define UREM_FormaDocZPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZPostCF();                                                           
   ~TREM_FormaDocZPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
