#ifndef UHLP_FormaSpiskaSprNaborInfBlockCFH                  
#define UHLP_FormaSpiskaSprNaborInfBlockCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaSpiskaSprNaborInfBlockCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaSpiskaSprNaborInfBlockCF();                                                           
   ~THLP_FormaSpiskaSprNaborInfBlockCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
