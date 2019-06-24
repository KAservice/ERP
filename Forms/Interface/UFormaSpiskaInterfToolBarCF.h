#ifndef UFormaSpiskaInterfToolBarCFH                  
#define UFormaSpiskaInterfToolBarCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaInterfToolBarCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaInterfToolBarCF();                                                           
   ~TFormaSpiskaInterfToolBarCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
