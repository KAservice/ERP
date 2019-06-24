#ifndef UREM_FormaElementaSprTypRabotGrpCFH                  
#define UREM_FormaElementaSprTypRabotGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprTypRabotGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprTypRabotGrpCF();                                                           
   ~TREM_FormaElementaSprTypRabotGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
