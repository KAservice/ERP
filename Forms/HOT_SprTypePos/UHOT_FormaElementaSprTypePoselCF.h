#ifndef UHOT_FormaElementaSprTypePoselCFH                  
#define UHOT_FormaElementaSprTypePoselCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaElementaSprTypePoselCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaElementaSprTypePoselCF();                                                           
   ~THOT_FormaElementaSprTypePoselCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
