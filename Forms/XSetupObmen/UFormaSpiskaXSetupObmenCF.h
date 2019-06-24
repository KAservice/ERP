#ifndef UFormaSpiskaXSetupObmenCFH                  
#define UFormaSpiskaXSetupObmenCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaXSetupObmenCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaXSetupObmenCF();                                                           
   ~TFormaSpiskaXSetupObmenCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
