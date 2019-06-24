#ifndef UREM_FormaElementaSprModelCFH                  
#define UREM_FormaElementaSprModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprModelCF();                                                           
   ~TREM_FormaElementaSprModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
