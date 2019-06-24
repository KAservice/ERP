#ifndef UREM_FormaElementaSprTypUslovCFH                  
#define UREM_FormaElementaSprTypUslovCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprTypUslovCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprTypUslovCF();                                                           
   ~TREM_FormaElementaSprTypUslovCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
