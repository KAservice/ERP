#ifndef UREM_FormaElementaSprTypDefectGrpCFH                  
#define UREM_FormaElementaSprTypDefectGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprTypDefectGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprTypDefectGrpCF();                                                           
   ~TREM_FormaElementaSprTypDefectGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
