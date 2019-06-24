#ifndef UREM_FormaDocZPerCFH                  
#define UREM_FormaDocZPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZPerCF();                                                           
   ~TREM_FormaDocZPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
