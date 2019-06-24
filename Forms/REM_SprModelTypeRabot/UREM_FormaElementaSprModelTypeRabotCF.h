#ifndef UREM_FormaElementaSprModelTypeRabotCFH                  
#define UREM_FormaElementaSprModelTypeRabotCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprModelTypeRabotCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprModelTypeRabotCF();                                                           
   ~TREM_FormaElementaSprModelTypeRabotCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
