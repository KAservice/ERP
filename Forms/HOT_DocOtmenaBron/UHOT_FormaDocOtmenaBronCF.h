#ifndef UHOT_FormaDocOtmenaBronCFH                  
#define UHOT_FormaDocOtmenaBronCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaDocOtmenaBronCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaDocOtmenaBronCF();                                                           
   ~THOT_FormaDocOtmenaBronCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
