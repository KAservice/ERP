#ifndef UREM_FormaDocZStartCFH                  
#define UREM_FormaDocZStartCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZStartCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZStartCF();                                                           
   ~TREM_FormaDocZStartCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
