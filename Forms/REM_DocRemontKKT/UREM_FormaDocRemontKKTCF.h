#ifndef UREM_FormaDocRemontKKTCFH                  
#define UREM_FormaDocRemontKKTCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocRemontKKTCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocRemontKKTCF();                                                           
   ~TREM_FormaDocRemontKKTCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
