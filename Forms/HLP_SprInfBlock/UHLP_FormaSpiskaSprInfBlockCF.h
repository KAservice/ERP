#ifndef UHLP_FormaSpiskaSprInfBlockCFH                  
#define UHLP_FormaSpiskaSprInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaSpiskaSprInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaSpiskaSprInfBlockCF();                                                           
   ~THLP_FormaSpiskaSprInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
