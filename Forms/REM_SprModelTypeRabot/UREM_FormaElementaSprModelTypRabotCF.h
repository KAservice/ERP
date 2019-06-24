#ifndef UREM_FormaElementaSprModelTypRabotCFH                  
#define UREM_FormaElementaSprModelTypRabotCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprModelTypRabotCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprModelTypRabotCF();                                                           
   ~TREM_FormaElementaSprModelTypRabotCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
