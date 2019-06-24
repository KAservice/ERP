#ifndef UHLP_FormaSpiskaSprNaborInfBlockSostavCFH                  
#define UHLP_FormaSpiskaSprNaborInfBlockSostavCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaSpiskaSprNaborInfBlockSostavCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaSpiskaSprNaborInfBlockSostavCF();                                                           
   ~THLP_FormaSpiskaSprNaborInfBlockSostavCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
