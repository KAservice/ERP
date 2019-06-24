#ifndef UObject1CVnCompCFH                  
#define UObject1CVnCompCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TObject1CVnCompCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TObject1CVnCompCF();                                                           
   ~TObject1CVnCompCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
