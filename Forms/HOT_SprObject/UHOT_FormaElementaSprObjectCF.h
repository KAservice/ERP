#ifndef UHOT_FormaElementaSprObjectCFH                  
#define UHOT_FormaElementaSprObjectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaElementaSprObjectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaElementaSprObjectCF();                                                           
   ~THOT_FormaElementaSprObjectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
