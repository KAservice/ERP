#ifndef UHOT_FormaDocViezdCFH                  
#define UHOT_FormaDocViezdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaDocViezdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaDocViezdCF();                                                           
   ~THOT_FormaDocViezdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
