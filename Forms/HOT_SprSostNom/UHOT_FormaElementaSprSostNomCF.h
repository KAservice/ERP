#ifndef UHOT_FormaElementaSprSostNomCFH                  
#define UHOT_FormaElementaSprSostNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaElementaSprSostNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaElementaSprSostNomCF();                                                           
   ~THOT_FormaElementaSprSostNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
