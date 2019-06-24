#ifndef UFormaSpiskaSetupCFH                  
#define UFormaSpiskaSetupCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSetupCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSetupCF();                                                           
   ~TFormaSpiskaSetupCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
