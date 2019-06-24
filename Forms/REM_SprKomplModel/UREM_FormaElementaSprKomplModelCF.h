#ifndef UREM_FormaElementaSprKomplModelCFH                  
#define UREM_FormaElementaSprKomplModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprKomplModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprKomplModelCF();                                                           
   ~TREM_FormaElementaSprKomplModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
