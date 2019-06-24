#ifndef UREM_FormaElementaSprTypRabotCFH                  
#define UREM_FormaElementaSprTypRabotCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprTypRabotCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprTypRabotCF();                                                           
   ~TREM_FormaElementaSprTypRabotCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
