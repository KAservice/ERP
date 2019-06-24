#ifndef UREM_FormaElementaSprDefectModelNeisprCFH                  
#define UREM_FormaElementaSprDefectModelNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprDefectModelNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprDefectModelNeisprCF();                                                           
   ~TREM_FormaElementaSprDefectModelNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
