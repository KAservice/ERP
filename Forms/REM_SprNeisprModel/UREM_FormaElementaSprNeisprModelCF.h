#ifndef UREM_FormaElementaSprNeisprModelCFH                  
#define UREM_FormaElementaSprNeisprModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprNeisprModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprNeisprModelCF();                                                           
   ~TREM_FormaElementaSprNeisprModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
