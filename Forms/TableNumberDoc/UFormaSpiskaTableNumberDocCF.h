#ifndef UFormaSpiskaTableNumberDocCFH                  
#define UFormaSpiskaTableNumberDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaTableNumberDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaTableNumberDocCF();                                                           
   ~TFormaSpiskaTableNumberDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
