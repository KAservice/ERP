#ifndef UHOT_FormaElementaSprCatNomCFH                  
#define UHOT_FormaElementaSprCatNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaElementaSprCatNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaElementaSprCatNomCF();                                                           
   ~THOT_FormaElementaSprCatNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
