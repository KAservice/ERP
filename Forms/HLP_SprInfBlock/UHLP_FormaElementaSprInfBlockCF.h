#ifndef UHLP_FormaElementaSprInfBlockCFH                  
#define UHLP_FormaElementaSprInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaElementaSprInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaElementaSprInfBlockCF();                                                           
   ~THLP_FormaElementaSprInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
