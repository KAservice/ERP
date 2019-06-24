#ifndef UREM_FormaElementaSprGrpNeisprCFH                  
#define UREM_FormaElementaSprGrpNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprGrpNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprGrpNeisprCF();                                                           
   ~TREM_FormaElementaSprGrpNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
