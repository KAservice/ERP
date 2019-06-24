#ifndef UREM_FormaElementaSprNeisprCFH                  
#define UREM_FormaElementaSprNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprNeisprCF();                                                           
   ~TREM_FormaElementaSprNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
