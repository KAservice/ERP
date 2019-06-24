#ifndef UREM_FormaElementaSprKKTCFH                  
#define UREM_FormaElementaSprKKTCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprKKTCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprKKTCF();                                                           
   ~TREM_FormaElementaSprKKTCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
