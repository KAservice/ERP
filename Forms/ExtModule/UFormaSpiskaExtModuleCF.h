#ifndef UFormaSpiskaExtModuleCFH                  
#define UFormaSpiskaExtModuleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaExtModuleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaExtModuleCF();                                                           
   ~TFormaSpiskaExtModuleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
