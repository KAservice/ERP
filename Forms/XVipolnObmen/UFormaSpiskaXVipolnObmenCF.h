#ifndef UFormaSpiskaXVipolnObmenCFH                  
#define UFormaSpiskaXVipolnObmenCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaXVipolnObmenCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaXVipolnObmenCF();                                                           
   ~TFormaSpiskaXVipolnObmenCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
