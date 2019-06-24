#ifndef UREM_FormaElementaSprActCategoryCFH                  
#define UREM_FormaElementaSprActCategoryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprActCategoryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprActCategoryCF();                                                           
   ~TREM_FormaElementaSprActCategoryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
