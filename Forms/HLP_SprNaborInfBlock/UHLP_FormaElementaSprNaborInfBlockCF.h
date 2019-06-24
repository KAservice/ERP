#ifndef UHLP_FormaElementaSprNaborInfBlockCFH                  
#define UHLP_FormaElementaSprNaborInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaElementaSprNaborInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaElementaSprNaborInfBlockCF();                                                           
   ~THLP_FormaElementaSprNaborInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
