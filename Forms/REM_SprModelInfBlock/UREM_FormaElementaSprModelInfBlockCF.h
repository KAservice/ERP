#ifndef UREM_FormaElementaSprModelInfBlockCFH                  
#define UREM_FormaElementaSprModelInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprModelInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprModelInfBlockCF();                                                           
   ~TREM_FormaElementaSprModelInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
