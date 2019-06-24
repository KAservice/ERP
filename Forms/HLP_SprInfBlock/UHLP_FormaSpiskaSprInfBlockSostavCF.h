#ifndef UHLP_FormaSpiskaSprInfBlockSostavCFH                  
#define UHLP_FormaSpiskaSprInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaSpiskaSprInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaSpiskaSprInfBlockSostavCF();                                                           
   ~THLP_FormaSpiskaSprInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
