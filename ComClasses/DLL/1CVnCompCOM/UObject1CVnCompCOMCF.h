#ifndef UObject1CVnCompCOMCFH
#define UObject1CVnCompCOMCFH
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TObject1CVnCompCOMCF : public IkanClassFactory
{                                                                             
public:                                                                       
   TObject1CVnCompCOMCF();
   ~TObject1CVnCompCOMCF();
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
