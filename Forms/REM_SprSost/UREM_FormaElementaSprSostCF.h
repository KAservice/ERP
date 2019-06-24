#ifndef UREM_FormaElementaSprSostCFH                  
#define UREM_FormaElementaSprSostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprSostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprSostCF();                                                           
   ~TREM_FormaElementaSprSostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
