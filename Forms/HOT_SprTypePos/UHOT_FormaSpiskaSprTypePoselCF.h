#ifndef UHOT_FormaSpiskaSprTypePoselCFH                  
#define UHOT_FormaSpiskaSprTypePoselCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaSpiskaSprTypePoselCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaSpiskaSprTypePoselCF();                                                           
   ~THOT_FormaSpiskaSprTypePoselCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
