#ifndef UREM_FormaGurVigrusokCFH                  
#define UREM_FormaGurVigrusokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurVigrusokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurVigrusokCF();                                                           
   ~TREM_FormaGurVigrusokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
