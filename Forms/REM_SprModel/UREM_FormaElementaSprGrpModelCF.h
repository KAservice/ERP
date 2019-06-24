#ifndef UREM_FormaElementaSprGrpModelCFH                  
#define UREM_FormaElementaSprGrpModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprGrpModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprGrpModelCF();                                                           
   ~TREM_FormaElementaSprGrpModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
