#ifndef UHOT_FormaDocRealCFH                  
#define UHOT_FormaDocRealCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaDocRealCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaDocRealCF();                                                           
   ~THOT_FormaDocRealCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
