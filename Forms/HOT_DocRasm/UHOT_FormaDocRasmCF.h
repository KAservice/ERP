#ifndef UHOT_FormaDocRasmCFH                  
#define UHOT_FormaDocRasmCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaDocRasmCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaDocRasmCF();                                                           
   ~THOT_FormaDocRasmCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
