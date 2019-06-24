#ifndef UHOT_DMDocRasmCFH                  
#define UHOT_DMDocRasmCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMDocRasmCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMDocRasmCF();                                                           
   ~THOT_DMDocRasmCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
