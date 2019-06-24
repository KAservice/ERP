#ifndef UREM_FormaSetupOtborCFH                  
#define UREM_FormaSetupOtborCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSetupOtborCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSetupOtborCF();                                                           
   ~TREM_FormaSetupOtborCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
